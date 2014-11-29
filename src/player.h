#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"
#include "tile.h"
#include <string>

/**
 * Player:
 * 	controllable Character
 */
class Player: public Character {
	private:
		static Player *curPlayer;
		static char race;

		static void cleanup();
	public:
		static const char SYMBOL_PLAYER = '@';

		static void setRace(char race);
		static void spawn(Tile *tile);
        static Player *getInstance();
        static void setInstance(Player *p);

		Player(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const std::string typeName);
		virtual ~Player() = 0;

		virtual void move(Cell *cell);
		virtual void pickUp(Cell *cell);
		virtual void engage(Cell *cell);
		virtual void killedBy(Character *other);

		virtual bool attackedBy(Character *other);
		void addAttackAction(Character *other, int damage);
		void addMissAction(Character *other);
};
#endif
