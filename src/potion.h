#ifndef ___POTION_H___
#define ___POTION_H___
#include <string>
#include "player.h"

class Cell;
class Drow;

class Potion: public Player {
	protected:
		Player *player;
		int multiplier;

		bool choosePickUp(bool revealed);
		void addPickupAction();
	public:
		static const char SYMBOL_POTION = 'P';
		
		// Constructor & destructor
		Potion(Tile *tile, std::string typeName);
		virtual ~Potion() = 0;

		// Potion methods
		bool pickedUpBy(Character *character);
		bool pickedUpBy(Drow *drow);

		// Delegating Entity methods
		Cell *getCell();
		char getSymbol();

		// Delegating Character methods
		void attack(Character *other);
		bool attackedBy(Character *other);
		bool isDead();

		void move(Cell *cell);
		void invokeAbility();

		int getHP();
		int getAtk();
		int getDef();
		int getGold();

		void setHP(int hp);
		void setAtk(int atk);
		void setDef(int def);
		void setGold(int gold);
		

		// Delegating Player methods
		void killedBy(Character *other);

		void pickUp(Cell *);
		void engage(Cell *);

		void equip(Sword *);
		void equip(Armor *);
		void useInventory(int index);
		void addInventory(Inventory *);

		Player *getBarePlayer();
		int getScore();
		Inventory *getInventoryAt(int index);
		Sword *getSword();
		Armor *getArmor();
};
#endif
