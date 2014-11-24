#ifndef ___SMALLTREASURE_H___
#define ___SMALLTREASURE_H___
#include "treasure.h"
class SmallTreasure: public Treasure {
	private:
	public:
		static const int GOLD_SMALL = 1;
		SmallTreasure(Tile *tile);
};
#endif
