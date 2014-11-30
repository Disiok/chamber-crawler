#ifndef ___HUMAN_H___
#define ___HUMAN_H___
#include "enemy.h"

class Goblin;

class Human: public Enemy {
	public:
		static const std::string NAME_HUMAN;
		static const char SYMBOL_HUMAN = 'H';
		static const int HP = 140;
		static const int ATK = 20;
		static const int DEF = 20;
		
		Human(Tile *tile);

        	void killedBy(Character *other);
        	void killedBy(Goblin *goblin);

		// Entity methods
		char getSymbol();
		std::string getName();
};
#endif
