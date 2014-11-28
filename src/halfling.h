#ifndef ___HALFLING_H___
#define ___HALFLING_H___
#include "enemy.h"
class Halfling: public Enemy {
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'L';
		static const int HP = 100;
		static const int ATK = 15;
		static const int DEF = 20;
		Halfling(Tile *tile);

		bool attackedBy(Character *other);
};
#endif
