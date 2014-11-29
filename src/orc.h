#ifndef ___ORC_H___
#define ___ORC_H___
#include "enemy.h"

class Character;
class Goblin;

class Orc: public Enemy {
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'O';
		static const int HP = 180;
		static const int ATK = 30;
		static const int DEF = 25;
		Orc(Tile *tile);

		int calculateDamageOn(Goblin *goblin);
        void attack(Goblin *goblin);
};
#endif
