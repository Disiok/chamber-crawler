#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___
#include "entity.h"
#include <string>

// Forward declaration
class Tile;

/** 
 * Character:
 * 	movable Entity
 */
class Character: public Entity {
	private:
		char typeIdentifier;
		std::string typeName;
		
		int healthPoint;
		int attack;
		int defense;

		int gold;

	public:
		// Constructor & Destructor
		Character(Tile *tile, int healthPoint, int attack, int defense, int gold, char typeIdentifier, std::string typeName);
		virtual ~Character() = 0;

		// Methods
		virtual void attack(Character *character);
		bool isAttacked(Character *character);
		virtual void move();
		virtual void die();

		// Accessors
		int getHealthPoint();
		int getAttack();
		int getDefense();

		// Mutators
		int modifyHealthPoint(int change);
		int modifyGold(int change);
};
#endif
