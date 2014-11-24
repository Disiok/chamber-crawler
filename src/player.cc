#include "player.h"
#include "tile.h"
#include "character.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
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
		case Drow::TYPE_ID:
			return new Drow();
		case Vampire::TYPE_ID:
			return new Vampire();
		case Troll::TYPE_ID:
			return new Troll();
		case Goblin::TYPE_ID:
			return new Goblin();
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
