#ifndef ___ENEMY_H___
#define ___ENEMY_H___
#include "character.h"
#include <string>

// Forward declaration
class Tile;

/**
 * Enemy:
 * 	uncontrollable Character
 */
class Enemy: public Character {
	private:
		bool isPlayerNearby();
		void move();

	public:
		Enemy(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const std::string typeName);
		virtual ~Enemy() = 0;

		virtual void performAction();
		virtual void killedBy(Character *other);
		void addAttackAction(Character *other, int damage);

		// Overrides
		bool isSteppable(Player *player);
};
#endif
