#ifndef ___DRAGONTREASURE_H___
#define ___DRAGONTREASURE_H___
#include "treasure.h"

class DragonTreasure: public Treasure {
	private:
		bool isGuarded;
	public:	
		static const int GOLD_DRAGON = 6;
		DragonTreasure(Tile *tile);

		bool isSteppable(Player *player);
			
};
#endif
