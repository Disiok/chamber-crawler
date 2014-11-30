#ifndef ___HUMAN_H___
#define ___HUMAN_H___
#include "enemy.h"

class Goblin;

class Human: public Enemy {
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'H';
		static const int HP = 140;
		static const int ATK = 20;
		static const int DEF = 20;
		Human(Tile *tile);

        void killedBy(Character *other);
        void killedBy(Goblin *goblin);
};
#endif
