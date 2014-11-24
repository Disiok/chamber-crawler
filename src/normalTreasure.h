#ifndef ___NORMALTREASURE_H___
#define ___NORMALTREASURE_H___
#include "treasure.h"
class NormalTreasure: public Treasure {
	private:
	public:
		static const int GOLD_NORMAL = 2;
		NormalTreasure(Tile *tile);
};
#endif
