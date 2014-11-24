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
        static Player *curPlayer;
        static void cleanup();

	public:
		static Player *getInstance(char type);
        static Player *getInstance();
		Player(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const std::string typeName);
		virtual ~Player() = 0;

		virtual void move(int direction);
		virtual void pickUp(int direction);
		virtual void killedBy(Character *other);
};
#endif
