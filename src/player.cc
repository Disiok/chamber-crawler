#include "player.h"
#include "tile.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "game.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

Player *Player::curPlayer = NULL;
char Player::race = '\0';

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
		case Shade::TYPE_ID:
			curPlayer = new Shade(tile);
			break;
		case Drow::TYPE_ID:
			curPlayer = new Drow(tile);
			break;
		case Vampire::TYPE_ID:
			curPlayer = new Vampire(tile);
			break;
		case Troll::TYPE_ID:
			curPlayer =  new Troll(tile);
			break;
		case Goblin::TYPE_ID:
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

Player::Player(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const std::string typeName):
	Character(tile, SYMBOL_PLAYER, hp, atk, def, 0, typeIdentifier, typeName) {}

Player::~Player() {}

void Player::move(Cell *cell) {
	if (cell->isSteppable(curPlayer)) {
		Character::move(cell);
	}
}

void Player::pickUp(Cell *cell) {
	cell->pickedUpBy(this);
}

void Player::engage(Cell *cell) {
	cell->attackedBy(this);
}

void Player::killedBy(Character *other) {
	cout << endl;
	cout << "You have been slain!" << endl;
	Game::getInstance()->restartOrQuit();
}

void Player::cleanup() {
    delete curPlayer;
}

void Player::addAttackAction(Character *other, int damage) {
	std::ostringstream oss;
	oss << "PC deals " << damage <<  " damage to " << other->getTypeId() << " (" << other->getHP() << " HP). ";
	Game::getInstance()->addAction(oss.str());
}

bool Player::attackedBy(Character *other) {
	if (rand() % 2) {
		Character::attackedBy(other);
	} else {
		other->addMissAction(this);
	}
	return true;
}

void Player::addMissAction(Character *other) {
	ostringstream oss;
	oss << "PC missed on " << other->getTypeId() << ". ";
	Game::getInstance()->addAction(oss.str());
}
