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
	
	public:
		Enemy(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const std::string typeName);
		virtual ~Enemy() = 0;
		
		virtual void move();
		virtual void performAction();
		virtual void killedBy(Character *other);
		virtual bool attackedBy(Character *other);
};
#endif
