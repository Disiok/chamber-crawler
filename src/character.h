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
		
		int hp;
		int atk;
		int def;
		int gold;

	public:
		// Constructor & Destructor
		Character(Tile *tile, int healthPoint, int attack, int defense, int gold, char typeIdentifier, std::string typeName);
		virtual ~Character() = 0;

		// Methods
		virtual void attack(Character *other);
		virtual bool attackedBy(Character *other);
		virtual void move();
		virtual void killedBy(Character *other);

		virtual bool isDead();

		// Accessors
		virtual int getHP();
		virtual int getAtk();
		virtual int getDef();
		virtual int getGold();

		// Mutators
		virtual void setHP(int hp);
		virtual void setAtk(int atk);
		virtual void setDef(int def);
		virtual void setGold(int gold);
};
#endif
