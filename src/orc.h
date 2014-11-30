#ifndef ___ORC_H___
#define ___ORC_H___
#include "enemy.h"

class Character;
class Goblin;

class Orc: public Enemy {
	public:
		static const std::string NAME_ORC;
		static const char SYMBOL_ORC = 'O';
		static const int HP = 180;
		static const int ATK = 30;
		static const int DEF = 25;
		Orc(Tile *tile);

		int calculateDamageOn(Goblin *goblin);
        void attack(Goblin *goblin);

	// Entity methods
	char getSymbol();
	std::string getName();
};
#endif
