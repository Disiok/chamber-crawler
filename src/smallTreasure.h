#ifndef ___SMALLTREASURE_H___
#define ___SMALLTREASURE_H___
#include "treasure.h"
class SmallTreasure: public Treasure {
	public:
		static const std::string NAME_SMALL_TREASURE;
		static const int GOLD_SMALL = 1;
		SmallTreasure(Tile *tile);

		// Entity method
		std::string getName();
};
#endif
