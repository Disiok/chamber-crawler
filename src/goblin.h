#ifndef ___GOBLIN_H___
#define ___GOBLIN_H___
#include <string>
#include "player.h"

// Forward declaration
class Tile;
class Human;
class Merchant;

class Goblin: public Player {
	public:
		static const std::string NAME_GOBLIN;
		static const char SYMBOL_GOBLIN = 'G';
		static const int HP = 110;
		static const int ATK = 15;
		static const int DEF = 20;

		Goblin(Tile *tile);
		
		int calculateGoldFrom(Character *other);
        	int calculateGoldFrom(Merchant *merchant);
        	int calculateGoldFrom(Human *human);
        	bool attackedBy(Character *other);
        	bool engage(Cell *cell);

		std::string getName();
};
#endif
