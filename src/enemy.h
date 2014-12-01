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
	public:
		// Constructor & destructor
		Enemy(Tile *tile, int hp, int atk, int def);
		virtual ~Enemy() = 0;

		// Entity method
		void performAction();
		void resetMoved();

		// Character method
		void addAttackAction(Character *other, int damage);
		void addMissAction(Character *);
		bool attackedBy(Goblin *);
		void killedBy(Character *);

		// Enemy method
		virtual void killedBy(Goblin *);
	protected:
		bool moved;
		
		// Enemy method
		virtual void addKilledAction(int gold);
		virtual void move();
		virtual bool isPlayerNearby();

};
#endif
