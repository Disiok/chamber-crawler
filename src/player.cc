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
 * getInstance(Tile *)
 * Sets current player to type based on char and returns the curPlayer
 */
Player *Player::getInstance(Tile *tile) {
#ifdef DEBUG
	cout << "Player::getInstance(Tile *)" << endl;
#endif
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
	return curPlayer;
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
	Character(tile, hp, atk, def, 0, typeIdentifier, typeName) {}

Player::~Player() {}

void Player::move(int direction) {

}

void Player::pickUp(int direction) {

}

void Player::killedBy(Character *other) {

}

void Player::cleanup() {
    delete curPlayer;
}
