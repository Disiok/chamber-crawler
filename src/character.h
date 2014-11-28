#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___
#include "entity.h"
#include <string>

// Forward declaration
class Tile;
class Cell;

/**
 * Character:
 * 	movable Entity
 */
class Character: public Entity {
	private:
		const char typeIdentifier;
		const std::string typeName;

		int hp;
		int atk;
		int def;
		int gold;

	public:
		// Constructor & Destructor
		Character(Tile *tile, char symbol, int hp, int atk, int def, int gold, const char typeIdentifier, const std::string typeName);
		virtual ~Character() = 0;

		// Methods
		virtual void attack(Character *other);
		virtual bool attackedBy(Character *other);
		virtual int calculateDamage(Character *other);
		virtual void addAttackAction(Character *other, int damage) = 0;
		void addMissAction(Character *other);
		virtual void move(Cell *cell);
		virtual void killedBy(Character *other) = 0;

		virtual bool isDead();

		// Accessors
		virtual int getHP();
		virtual int getAtk();
		virtual int getDef();
		virtual int getGold();

		char getTypeId();
		std::string getTypeName();

		// Mutators
		virtual void setHP(int hp);
		virtual void setAtk(int atk);
		virtual void setDef(int def);
		virtual void setGold(int gold);
};
#endif
