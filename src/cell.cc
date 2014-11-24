#include "cell.h"
#include "wall.h"
#include "door.h"
#include "passage.h"
#include "tile.h"
#include "shade.h"
#include "stair.h"
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
	Tile *t = dynamic_cast<Tile *>(this);
	/*if (true || roll >= 1 && roll < 5) {
		t->setEntity(new Shade(t));
	} else if (roll >= 5 && roll < 8) {
		t->setEntity(new Dwarf(t));
	} else if (roll >= 8 && roll < 13) {
		t->setEntity(new Halfling(t));
	} else if (roll >= 13 && roll < 15) {
		t->setEntity(new Elf(t));
	} else if (roll >= 15 && roll < 17) {
		t->setEntity(new Orc(t));
	} else {
		t->setEntity(new Merchant(t));
	}*/
}

/* *
 * spawnPotion
 *     1/6 for each potion
 */
void Cell::spawnPotion() {
	// TODO: uncomment once .h and .cc for each potion is added
	/*int roll = rand() % 6 + 1;
	Tile *t = dynamic_cast<Tile *>(this);
	switch(roll) {
		case: 1
			t->setEntity(new RestoreHealth(t));
			break;
		case: 2
			t->setEntity(new PoisonHealth(t));
			break;
		case: 3
			t->setEntity(new BoostAtk(t));
			break;
		case: 4
			t->setEntity(new BoostDef(t));
			break;
		case: 5
			t->setEntity(new WoundDef(t));
			break;
		default:
			t->setEntity(new WoundAtk(t));
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
	Tile *t = dynamic_cast<Tile *>(this);
	if (roll >= 1 && roll < 6) {
		t->setEntity(new NormalTreasure(t));
	} else if (roll == 6) {
		t->setEntity(new DragonTreasure(t));
	} else {
		t->setEntity(new SmallTreasure(t));
	}*/
}

/* *
 * spawnStair
 * Spawns stair entity in a room without the Player
 */
void Cell::spawnStair() {
	Tile *t = dynamic_cast<Tile *>(this);
	t->setEntity(Stair::getInstance(t));
}

/* *
 * spawnPlayer
 * Spawn player singleton in any room
 */
void Cell::spawnPlayer() {
	Tile *t = dynamic_cast<Tile *>(this);
	// TODO: uncomment once we figure out how to set initial tile for player
	//t->setEntity(Player::getInstance(t));
}