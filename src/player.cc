#include "player.h"
#include "game.h"
#include "tile.h"

// Special characters
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

// Equipments
#include "sword.h"
#include "armor.h"

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

Player *Player::curPlayer = NULL;
char Player::race = '\0';

// Static functions
bool Player::setRace(char race) {
	switch (race) {
		case Shade::SYMBOL_SHADE:
		case Drow::SYMBOL_DROW:
		case Vampire::SYMBOL_VAMPIRE:
		case Troll::SYMBOL_TROLL:
		case Goblin::SYMBOL_GOBLIN:
			Player::race = race;
			return true;
		default:
			return false;
	}
}

/* *
 * spawn(Tile *)
 * 	Sets current player to type based on char
 */
void Player::spawn(Tile *tile) {
#ifdef DEBUG
	cout << "Player::spawn(Tile *)" << endl;
#endif
	if (curPlayer) {
		curPlayer->setCell(tile);
	} else {
		switch (race) {
			case Shade::SYMBOL_SHADE:
				curPlayer = new Shade(tile);
				break;
			case Drow::SYMBOL_DROW:
				curPlayer = new Drow(tile);
				break;
			case Vampire::SYMBOL_VAMPIRE:
				curPlayer = new Vampire(tile);
				break;
			case Troll::SYMBOL_TROLL:
				curPlayer =  new Troll(tile);
				break;
			case Goblin::SYMBOL_GOBLIN:
				curPlayer =  new Goblin(tile);
				break;
			default:
				break;
		}
		atexit(cleanup);
		Game::getInstance()->addAction("Player character has spawned.");
	}
}

/* *
 * getInstance()
 * 	Returns the curPlayer
 */
Player *Player::getInstance() {
    return curPlayer;
}

void Player::setInstance(Player *p) {
    curPlayer = p;
}

void Player::cleanup() {
	if (curPlayer) {
		Cell *cell = curPlayer->getCell();
		if (cell) {
			cell->clearEntity();
		}
	}
	delete curPlayer;
	curPlayer = NULL;
}

// Constructor & destructor
Player::Player(Tile *tile, int hp, int atk, int def):
	Character(tile, hp, atk, def, 0), sword(NULL), armor(NULL) {
	for (int i = 0; i < MAX_INVENTORY; i ++) {
		inventory[i] = NULL;
	}	
}

Player::~Player() {
	delete sword;
	delete armor;
	for (int i = 0; i < MAX_INVENTORY; i ++){
		delete inventory[i];
	}
}

// Player methods
bool Player::pickUp(Cell *cell) {
	return cell->pickedUpBy(this);
}

bool Player::engage(Cell *cell) {
	return cell->attackedBy(this);
}

void Player::equip(Sword *sword) {
	if (this->sword) {
		delete this->sword;

		ostringstream oss;
		oss << "Discarded a " << this->sword->getName() << ". ";
		Game::getInstance()->addAction(oss.str());

	}
	this->sword = sword;
	
	ostringstream oss;
	oss << "Equipped a " << this->sword->getName() << ". ";
	Game::getInstance()->addAction(oss.str());
}

void Player::equip(Armor *armor) {
	if (this->armor) {
		delete this->armor;

		ostringstream oss;
		oss << "Equipped a " << this->armor->getName() << ". ";
		Game::getInstance()->addAction(oss.str());

	}
	this->armor = armor;

	ostringstream oss;
	oss << "Equipped a " << this->armor->getName() << ". ";
	Game::getInstance()->addAction(oss.str());

}

bool Player::useInventory(int index) {
	Inventory *item = inventory[index];
	if (item) {
		inventory[index] = NULL;
		item->usedBy(this);
		return true;
	} else {
		return false;
	}
}

void Player::addInventory(Inventory *item) {
	bool added = false;
	for (int i = 0; i < MAX_INVENTORY; i ++) {
		if (!inventory[i]) {
			inventory[i] = item;
			added = true;
			break;
		}
	}
	if (!added) {
		cout << "Inventory full, choose an item to discard: ";
		int index;
		cin >> index;
		if (index >= 0 && index < MAX_INVENTORY) {
			delete inventory[index];
			inventory[index] = item;
		} else {
			delete item;
		}
	}
}


Player *Player::getBarePlayer() {
	return this;
}

int Player::getScore() {
	return getGold();
}

Inventory *Player::getInventoryAt(int index) {
	if (index >= 0 && index < MAX_INVENTORY) {
		return inventory[index];
	} else {
		return NULL;
	}
}

Sword *Player::getSword() {
	return sword;
}

Armor *Player::getArmor() {
	return armor;
}

// Character methods
bool Player::move(Cell *cell) {
	if (cell->isSteppable(curPlayer)) {
		Character::move(cell);
		return true;
	} else {
		return false;
	}
}

bool Player::attackedBy(Character *other) {
	if (rand() % 2) {
		Character::attackedBy(other);
	} else {
		other->addMissAction(this);
	}
	return true;
}

void Player::killedBy(Character *character) {
	cout << endl;
	cout << "You have been slain by " << character->getSymbol() << "!" << endl;
	cout << "Your score is: " << getScore() << endl;
	cout << endl;
	Game::getInstance()->restartOrQuit();
}


void Player::addAttackAction(Character *other, int damage) {
	std::ostringstream oss;
	oss << "PC deals " << damage <<  " damage to " << other->getSymbol() << " (" << other->getHP() << " HP). ";
	Game::getInstance()->addAction(oss.str());
}

void Player::addMissAction(Character *other) {
	ostringstream oss;
	oss << "PC missed on " << other->getSymbol() << ". ";
	Game::getInstance()->addAction(oss.str());
}

int Player::getAtk() {
	if (sword) {
		return Character::getAtk() + sword->getAtk();
	} else  {
		return Character::getAtk();
	}
}

int Player::getDef() {
	if (armor) {
		return Character::getDef() + armor->getDef();
	} else {
		return Character::getDef();
	}
}

char Player::getSymbol() {
	return SYMBOL_PLAYER;
}
