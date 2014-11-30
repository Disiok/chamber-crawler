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
		const char typeIdentifier;
		const int maxHP;

	protected:
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
		virtual void attack(Dwarf *dwarf);
		virtual void attack(Drow *drow);
		virtual void attack(Goblin *goblin);
		virtual bool attackedBy(Character *other);
		virtual bool attackedBy(Goblin *goblin);
		virtual int calculateDamageOn(Character *other);
		virtual int calculateDamageOn(Goblin *goblin);
		virtual void addAttackAction(Character *other, int damage) = 0;

		virtual void addMissAction(Character *other) = 0;

		virtual int calculateGoldFrom(Character *other);
		virtual int calculateGoldFrom(Human *human);
		virtual int calculateGoldFrom(Merchant *merchant);
		virtual void move(Cell *cell);
		virtual void killedBy(Character *other) = 0;

		virtual bool isDead();
		virtual void invokeAbility();

		// Accessors
		virtual int getHP();
		virtual int getAtk();
		virtual int getDef();
		virtual int getGold();

		char getTypeId();
		virtual std::string getTypeName();

		// Mutators
		virtual void setHP(int hp);
		virtual void setAtk(int atk);
		virtual void setDef(int def);
		virtual void setGold(int gold);
};
#endif
