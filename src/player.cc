#include "player.h"
#include "tile.h"
#include "character.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include <string>
#include <iostream>
using namespace std;

Player *Player::getInstance(char type) {
#ifdef DEBUG
	cout << "Player::getInstance" << endl;
#endif
	switch (type) {
		case Shade::TYPE_ID:
			return new Shade();
		default:
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
