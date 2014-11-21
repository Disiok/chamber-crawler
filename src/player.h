#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"
#include <string>

/**
 * Player:
 * 	controllable Character
 */
class Player: public Character {
	private:

	public:
		Player(Tile *tile, int healthPoint, int attack, int defense, char typeIdentifier, std::string typeName);
		virtual ~Player() = 0;
		
		void move(int direction);
		void pickUp(int direction);
		void die();

};
#endif
