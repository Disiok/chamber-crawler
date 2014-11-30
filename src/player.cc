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
void Player::setRace(char race) {
	Player::race = race;
}

/* *
 * spawn(Tile *)
 * 	Sets current player to type based on char
 */
void Player::spawn(Tile *tile) {
#ifdef DEBUG
	cout << "Player::spawn(Tile *)" << endl;
#endif
	delete curPlayer;
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
	Cell *cell = curPlayer->getCell();
	if (cell) {
		cell->clearEntity();
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
void Player::pickUp(Cell *cell) {
	cell->pickedUpBy(this);
}

void Player::engage(Cell *cell) {
	cell->attackedBy(this);
}

void Player::equip(Sword *sword) {
	this->sword = sword;
}

void Player::equip(Armor *armor) {
	this->armor = armor;
}

void Player::useInventory(int index) {
	Inventory *item = inventory[index];
	if (item) {
		inventory[index] = NULL;
		item->usedBy(this);
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
	return curPlayer;
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
void Player::move(Cell *cell) {
	if (cell->isSteppable(curPlayer)) {
		Character::move(cell);
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

void Player::killedBy(Character *) {
	cout << endl;
	cout << "You have been slain!" << endl;
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
