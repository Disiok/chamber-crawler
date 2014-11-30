#ifndef ___POTION_H___
#define ___POTION_H___
#include <string>
#include "player.h"

class Cell;
class Drow;

class Potion: public Player {
	protected:
		Player *player;
		bool choosePickUp(bool revealed);
		void addPickupAction();
		int multiplier;
	public:
		static const char SYMBOL_POTION = 'P';
		Potion(Tile *tile, std::string typeName);

		// Delegating Entity methods
		bool pickedUpBy(Character *character);
		bool pickedUpBy(Drow *drow);

		// Delegating Player methods
		void move(Cell *cell);
		void killedBy(Character *other);

		// Delegating Character methods
		void attack(Character *other);
		bool attackedBy(Character *other);

		bool isDead();

		int getHP();
		int getAtk();
		int getDef();
		int getGold();

		void setHP(int hp);
		void setAtk(int atk);
		void setDef(int def);
		void setGold(int gold);

		// Delegating Entity methods
		Cell *getCell();
		char getSymbol();
		std::string getTypeName();

		// Other
		virtual Player *getBarePlayer();
};
#endif
