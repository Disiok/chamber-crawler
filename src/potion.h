#ifndef ___POTION_H___
#define ___POTION_H___
#include <string>
#include "player.h"

class Cell;

class Potion: public Player {
	protected:
		Player *player;
	public:
		static const char SYMBOL_POTION = 'P';
		Potion(Tile *tile, std::string typeIdentifier);

		bool pickedUpBy(Character *character);

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

		// Other
		virtual Player *getBarePlayer();
};
#endif
