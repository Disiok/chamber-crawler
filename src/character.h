#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___
#include "entity.h"
#include <string>

// Forward declaration
class Tile;
class Cell;
class Drow;
class Dwarf;
class Goblin;
class Human;
class Merchant;

/**
 * Character:
 * 	movable Entity
 */
class Character: public Entity {
	private:
		const int maxHP;

	protected:
		int hp;
		int atk;
		int def;
		int gold;

	public:
		// Constructor & destructor
		Character(Tile *tile, int hp, int atk, int def, int gold);
		virtual ~Character() = 0;

		// Combat methods
		virtual void attack(Character *);
		virtual void attack(Dwarf *);
		virtual void attack(Drow *);
		virtual void attack(Goblin *);

		virtual bool attackedBy(Character *);
		virtual bool attackedBy(Goblin *);

		virtual void killedBy(Character *) = 0;
		virtual bool isDead();


		virtual void addAttackAction(Character *other, int damage) = 0;
		virtual void addMissAction(Character *) = 0;

		virtual int calculateDamageOn(Character *);
		virtual int calculateDamageOn(Goblin *);
		
		virtual int calculateGoldFrom(Character *);
		virtual int calculateGoldFrom(Human *);
		virtual int calculateGoldFrom(Merchant *);
		
		// Other methods
		virtual void move(Cell *);
		virtual void invokeAbility();

		// Accessors
		virtual int getHP();
		virtual int getAtk();
		virtual int getDef();
		virtual int getGold();

		// Mutators
		virtual void setHP(int);
		virtual void setAtk(int);
		virtual void setDef(int);
		virtual void setGold(int);
};
#endif
