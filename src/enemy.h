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
		void addAttackAction(Character *other, int damage);
	protected:
		void addKilledAction(int gold);
		virtual void move();
	public:
		Enemy(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const std::string typeName);
		virtual ~Enemy() = 0;

		virtual void performAction();
		virtual void killedBy(Character *other);
		virtual void killedBy(Goblin *goblin);
		virtual bool attackedBy(Goblin *goblin);
		virtual bool isPlayerNearby();


		// Overrides
		bool isSteppable(Player *player);

		void addMissAction(Character *other);
};
#endif
