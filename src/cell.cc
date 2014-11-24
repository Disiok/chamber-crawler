#include "cell.h"
#include "wall.h"
#include "door.h"
#include "passage.h"
#include "tile.h"
#include "shade.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Forward Declaration
class Player;
class Enemy;

Cell::Cell(int i, int j, char symbol):
	i(i), j(j), symbol(symbol) {}

Cell::~Cell() {}

bool Cell::performAction() {
	return false;
}

bool Cell::isSteppable(Player *player) {
	return false;
}

bool Cell::isSteppable(Enemy *enemy) {
	return true;
}

Cell *Cell::getInstance(int i, int j, char id) {
	if (id == '|' || id == '-') {
		return new Wall(i, j, id);
	} else if (id == '.') {
		return new Tile(i, j);
	} else if (id == '#') {
		return new Passage(i, j);
	} else if (id == '+') {
		return new Door(i, j);
	} else {
		return NULL;
	}
}

char Cell::getSymbol() {
	return symbol;
}

/* *
 * spawnEnemy
 * 	  Human: 	2/9 = 4/18
 * 	  Dwarf: 	3/18
 * 	  Halfling:	5/18
 * 	  Elf:		1/9 = 2/18
 * 	  Orc: 		1/9 = 2/18
 * 	  Merchant: 1/9 = 2/18
 */
void Cell::spawnEnemy() {
	// TODO: uncomment when .h and .cc are added
	int roll = rand() % 18 + 1;
	if (true || roll >= 1 && roll < 5) {
		dynamic_cast<Tile *>(this)->setEntity(new Shade(dynamic_cast<Tile *>(this)));
	} /*else if (roll >= 5 && roll < 8) {
		dynamic_cast<Tile *>(this)->setEntity(new Dwarf());
	} else if (roll >= 8 && roll < 13) {
		dynamic_cast<Tile *>(this)->setEntity(new Halfling());
	} else if (roll >= 13 && roll < 15) {
		dynamic_cast<Tile *>(this)->setEntity(new Elf());
	} else if (roll >= 15 && roll < 17) {
		dynamic_cast<Tile *>(this)->setEntity(new Orc());
	} else {
		dynamic_cast<Tile *>(this)->setEntity(new Merchant());
	}*/
}

/* *
 * spawnPotion
 *     1/6 for each potion
 */
void Cell::spawnPotion() {
	// TODO: uncomment once .h and .cc for each potion is added
	/*int roll = rand() % 6 + 1;
	switch(roll) {
		case: 1
			dynamic_cast<Tile *>(this)->setEntity(new RestoreHealth());
			break;
		case: 2
			dynamic_cast<Tile *>(this)->setEntity(new PoisonHealth());
			break;
		case: 3
			dynamic_cast<Tile *>(this)->setEntity(new BoostAtk());
			break;
		case: 4
			dynamic_cast<Tile *>(this)->setEntity(new BoostDef());
			break;
		case: 5
			dynamic_cast<Tile *>(this)->setEntity(new WoundDef());
			break;
		default:
			dynamic_cast<Tile *>(this)->setEntity(new WoundAtk());
			break;
	} */
}

/* *
 * spawnTreasure
 *     Normal:	5/8
 * 	   Dragon: 	1/8
 *	   Small: 	1/4 = 2/8
 */
void Cell::spawnTreasure() {
	// TODO: uncomment when .h and .cc are added
	/*int roll = rand() % 8 + 1;
	cout<<"Spawning Enemy"<<endl;
	if (roll >= 1 && roll < 6) {
		dynamic_cast<Tile *>(this)->setEntity(new NormalTreasure());
	} else if (roll == 6) {
		dynamic_cast<Tile *>(this)->setEntity(new DragonTreasure());
	} else {
		dynamic_cast<Tile *>(this)->setEntity(new SmallTreasure());
	}*/
}

/* *
 * spawnStair
 * Spawns stair entity in a room without the Player
 */
void Cell::spawnStair() {
	dynamic_cast<Tile *>(this)->setEntity(Stair::getInstance());
}

/* *
 * spawnPlayer
 * Spawn player singleton in any room
 */
void Cell::spawnPlayer() {
	dynamic_cast<Tile *>(this)->setEntity(Player::getInstance());
}