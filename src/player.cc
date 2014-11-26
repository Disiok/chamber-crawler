#include "player.h"
#include "tile.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

Player *Player::curPlayer = NULL;
char Player::race = '\0';

void Player::setRace(char race) {
	Player::race = race;
}

/* *
 * spawn(Tile *)
 * Sets current player to type based on char and returns the curPlayer
 */
void Player::spawn(Tile *tile) {
#ifdef DEBUG
	cout << "Player::spawn(Tile *)" << endl;
#endif
	if (!curPlayer) {
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
	}
}

/* *
 * getInstance()
 * Returns the curPlayer
 */
Player *Player::getInstance() {
#ifdef DEBUG
    cout << "Player::getInstance()" << endl;
#endif
    return curPlayer;
}

Player::Player(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const std::string typeName):
	Character(tile, SYMBOL_PLAYER, hp, atk, def, 0, typeIdentifier, typeName) {}

Player::~Player() {}

void Player::move(Cell *cell) {
    if (cell->isSteppable(curPlayer)) {
        cell->setEntity(curPlayer);
        Character::move(cell);
    }
}

void Player::pickUp(Cell *cell) {

}

void Player::engage(Cell *cell) {

}

void Player::killedBy(Character *other) {

}

void Player::cleanup() {
    delete curPlayer;
}
