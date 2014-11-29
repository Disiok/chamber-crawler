#include "tile.h"

#include "entity.h"
#include "character.h"
#include "enemy.h"
#include "player.h"
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

// Potions
#include "restoreHealth.h"
#include "poisonHealth.h"
#include "boostAtk.h"
#include "woundAtk.h"
#include "boostDef.h"
#include "woundDef.h"

#include <iostream>
#include <cstdlib>
using namespace std;

Tile::Tile(int i, int j, Floor* floor):
	Cell(i, j, SYMBOL_TILE, floor) {}

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
		setEntity(new Human(this));
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
	int roll = rand() % 6 + 1;
	switch(roll) {
		case 1:
			setEntity(new RestoreHealth(this));
			break;
		case 2:
			setEntity(new PoisonHealth(this));
			break;
		case 3:
			setEntity(new BoostAtk(this));
			break;
		case 4:
			setEntity(new BoostDef(this));
			break;
		case 5:
			setEntity(new WoundDef(this));
			break;
		default:
			setEntity(new WoundAtk(this));
			break;
	}
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
	Stair::spawn(this);
	setEntity(Stair::getInstance());
}

/* *
 * spawnPlayer
 * Spawn player singleton in any room
 */
void Tile::spawnPlayer() {
	Player::spawn(this);
	setEntity(Player::getInstance());
}
