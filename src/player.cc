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

/* *
 * getInstance(char)
 * Sets current player to type based on char and returns the curPlayer
 */
Player *Player::getInstance(char type) {
#ifdef DEBUG
	cout << "Player::getInstance(char)" << endl;
#endif
	switch (type) {
		case Shade::TYPE_ID:
			curPlayer = new Shade();
			break;
		case Drow::TYPE_ID:
			curPlayer = new Drow();
			break;
		case Vampire::TYPE_ID:
			curPlayer = new Vampire();
			break;
		case Troll::TYPE_ID:
			curPlayer =  new Troll();
			break;
		case Goblin::TYPE_ID:
			curPlayer =  new Goblin();
			break;
		default:
			break;
	}
	atexit(cleanup);
	return curPlayer;
}

/* *
 * getInstance(char)
 * Returns the curPlayer
 */
Player *Player::getInstance() {
#ifdef DEBUG
    cout << "Player::getInstance()" << endl;
#endif
    if (curPlayer) {
        return curPlayer;
    } else {
        return NULL;
    }
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