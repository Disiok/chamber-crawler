#include "floor.h"
#include "chamber.h"
#include "tile.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "cell.h"
#include <string>
#include "stair.h"
#include "player.h"
#include "dragon.h"
#include "dragonTreasure.h"
using namespace std;

Floor::Floor() {
	for (int i = 0; i < MAX_ROW; i ++) {
		for (int j = 0; j < MAX_COLUMN; j ++) {
			map[i][j] = NULL;
		}
	}
	for (int i = 0; i < MAX_CHAMBERS; i ++) {
		chambers[i] = NULL;
	}
}

Floor::~Floor() {
	for (int i = 0; i < MAX_ROW; i ++) {
		for (int j = 0; j < MAX_COLUMN; j ++) {
			if (map[i][j] != NULL && map[i][j]->getSymbol() != Stair::SYMBOL_STAIR && map[i][j]->getSymbol() != Player::SYMBOL_PLAYER) {
				map[i][j]->destroyEntity();
			}
			delete map[i][j];
		}
	}
	for (int i = 0; i < MAX_CHAMBERS; i ++) {
		delete chambers[i];
	}
}

/* *
 * floodChamber
 * Gets all the cells in the chamber by flooding it start from (i, j)
 * Marks off flooded tiles in the rows parameter, and returns a new Chamber
 */
void Floor::floodChamber(int i, int j, string (*rows)[MAX_ROW], std::vector<Tile *> *tiles) {
	tiles->push_back(dynamic_cast<Tile *>(map[i][j]));
	(*rows)[i][j] = '~';
	if (i > 0) {
		if ((*rows)[i-1][j] == '.') {
			floodChamber(i-1, j, rows, tiles);
		}
	}
	if (j > 0) {
		if ((*rows)[i][j-1] == '.') {
			floodChamber(i, j-1, rows, tiles);
		}
	}
	if (i < MAX_ROW) {
		if ((*rows)[i+1][j] == '.') {
			floodChamber(i+1, j, rows, tiles);
		}
	}
	if (j < MAX_COLUMN) {
		if ((*rows)[i][j+1] == '.') {
			floodChamber(i, j+1, rows, tiles);
		}
	}
}

void Floor::loadFromFile(std::ifstream *floorStream) {
#ifdef DEBUG
	cout << "Floor::loadFromFile()" << endl;
#endif
	// 'rows' stores the floor to be later flooded to create chambers
	string rows[MAX_ROW];
	string line;
	for (int i = 0; i < MAX_ROW; i ++) {
		getline(*floorStream, line);
		rows[i] = line;
		for (int j = 0; j < MAX_COLUMN; j ++) {
			map[i][j] = Cell::getInstance(i, j, line[j], this);
		}
	}

	// If dragons and their respective treasures are not linked, link them
	for (int i = 0; i < MAX_ROW; i ++) {
		for (int j = 0; j < MAX_COLUMN; j ++) {
			if (map[i][j]) {
				Entity *e = map[i][j]->getEntity();
				Dragon *d = dynamic_cast<Dragon *>(e);
				if (d) {
				    // Find an unlinked dragonTreasure
					bool found = false;
				    for (int a = -1 ; a <= 1 && !found ; a++) {
				        for (int b = -1 ; b <= 1 && !found ; b++) {
				        	DragonTreasure *dt = dynamic_cast<DragonTreasure *>(map[i+a][j+b]->getEntity());
				            if (dt && dt->isSteppable(Player::getInstance())) {
				                d->setTreasure(dt);
				                dt->lock();
				                found = true;
				            }
				        }
				    }
				}
			}
		}
	}

	// Going through every floor tile and flooding each chamber
	int numChambers = 0;
	for (int i = 0 ; i < MAX_ROW && numChambers < MAX_CHAMBERS; i++) {
		for (int j = 0 ; j < MAX_COLUMN && numChambers < MAX_CHAMBERS; j++) {
			if (rows[i][j] == '.') {
				vector<Tile *> tiles;
				floodChamber(i, j, &rows, &tiles);
				chambers[numChambers] = new Chamber(tiles);
				numChambers++;
			}
		}
	}
}

void Floor::displayFloor() {
#ifdef DEBUG
	cout << "Floor::displayFloor" << endl;
#endif

	for (int i = 0; i < MAX_ROW; i ++) {
		for (int j = 0; j < MAX_COLUMN; j ++) {
			if (map[i][j]) {
				cout << map[i][j]->getSymbol();
			} else {
				cout << ' ';
			}
		}
		cout << endl;
	}

}

/* *
 * spawn
 *  Spawns player, stairs and all potions, gold, enemies on floor.
 */
void Floor::spawn() {
#ifdef DEBUG
	cout<<"Floor::spawn"<<endl;
#endif

	// Player
	Chamber *playerChamber = getRandomChamber();
	playerChamber->getRandomTile()->spawnPlayer();

	// Stairs
	Chamber *stairsChamber = getRandomChamber();
#ifdef DEBUG
	while (stairsChamber != playerChamber) {
#else
	while (stairsChamber == playerChamber) {
#endif
		stairsChamber = getRandomChamber();
	}
	stairsChamber->getRandomTile()->spawnStair();

	// Potions
	for (int i = 0 ; i < NUM_POTION ; i++) {
		getRandomTile()->spawnPotion();
	}
	// Gold
		// spawning a dragon beside the dragonTreasure counts towards enemy count
	int numDragons = 0;
	for (int i = 0 ; i < NUM_GOLD ; i++) {
		if (getRandomTile()->spawnTreasure()) {
			numDragons++;
		}
	}
	// Enemies
	for (int i = 0 ; i < NUM_ENEMY - numDragons ; i++) {
		getRandomTile()->spawnEnemy();
	}
#ifdef DLC
	// Equipments
	for (int i = 0; i < NUM_EQUIP; i ++) {
		getRandomTile()->spawnEquipment();
	}
#endif
}

Chamber *Floor::getRandomChamber() {
	return chambers[rand() % MAX_CHAMBERS];
}

Tile *Floor::getRandomTile() {
	return getRandomChamber()->getRandomTile();
}

Cell *Floor::getCell(int i, int j) {
    return map[i][j];
}

void Floor::performAction() {
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COLUMN; j++) {
			if (map[i][j] != NULL) {
				map[i][j]->performAction();
			}
		}
	}
}

void Floor::resetMoved() {
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COLUMN; j++) {
			if (map[i][j] != NULL) {
				map[i][j]->resetMoved();
			}
		}
	}
}
