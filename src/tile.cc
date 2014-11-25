#include "tile.h"
#include "entity.h"
#include "enemy.h"
#include "shade.h"
#include "stair.h"

// Treasures
#include "normalTreasure.h"
#include "smallTreasure.h"
#include "dragonTreasure.h"

// Enemies
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"

#include "character.h"
#include <iostream>
using namespace std;

Tile::Tile(int i, int j):
	Cell(i, j, SYMBOL_TILE), entity(NULL) {}

bool Tile::hasEntity() {
	if (entity) {
		return true;
	} else {
		return false;
	}
}
void Tile::destroyEntity() {
	delete entity;
}

void Tile::clearEntity() {
	entity = NULL;
}

void Tile::setEntity(Entity *entity) {
	this->entity = entity;
}

bool Tile::steppedOnBy(Character *other) {
	if (entity) {
		return entity->steppedOnBy(other);
	} else {
		return false;
	}
}

bool Tile::pickedUpBy(Character *other) {
	if (entity) {
		return entity->pickedUpBy(other);
	} else {
		return false;
	}
}

bool Tile::attackedBy(Character *other) {
	if (entity) {
		return entity->attackedBy(other);
	} else {
		return false;
	}
}

bool Tile::isSteppable(Player *player) {
	if (entity) {
		return entity->isSteppable(player);
	} else {
		return true;
	}
}

bool Tile::isSteppable(Enemy *enemy) {
	if (entity) {
		return entity->isSteppable(enemy);
	} else {
		return true;
	}
}

char Tile::getSymbol() {
	if (entity) {
		return entity->getSymbol();
	} else {
		return Cell::getSymbol();
	}
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
void Tile::spawnEnemy() {
	int roll = rand() % 18 + 1;
	if (roll >= 1 && roll < 5) {
		setEntity(new Shade(this));
	} else if (roll >= 5 && roll < 8) {
		setEntity(new Dwarf(this));
	} else if (roll >= 8 && roll < 13) {
		setEntity(new Halfling(this));
	} else if (roll >= 13 && roll < 15) {
		setEntity(new Elf(this));
	} else if (roll >= 15 && roll < 17) {
		setEntity(new Orc(this));
	} else {
		setEntity(new Merchant(this));
	}
}

/* *
 * spawnPotion
 *     1/6 for each potion
 */
void Tile::spawnPotion() {
	// TODO: uncomment once .h and .cc for each potion is added
	/*int roll = rand() % 6 + 1;
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
 * 	Normal:	5/8
 * 	Dragon: 1/8
 *	Small: 	1/4 = 2/8
 */
void Tile::spawnTreasure() {
	int roll = rand() % 8 + 1;
	if (roll >= 1 && roll < 6) {
		setEntity(new NormalTreasure(this));
	} else if (roll == 6) {
		setEntity(new DragonTreasure(this));
	} else {
		setEntity(new SmallTreasure(this));
	}
}

/* *
 * spawnStair
 * Spawns stair entity in a room without the Player
 */
void Tile::spawnStair() {
	setEntity(Stair::getInstance(this));
}

/* *
 * spawnPlayer
 * Spawn player singleton in any room
 */
void Tile::spawnPlayer() {
	setEntity(Player::getInstance(this));
}
