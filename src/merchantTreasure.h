#ifndef ___MERCHANTTREASURE_H___
#define ___MERCHANTTREASURE_H___
#include "treasure.h"
class MerchantTreasure: public Treasure {
	private:
	public:
		static const int GOLD_MERCHANT = 4;
		MerchantTreasure(Tile *tile);
};
#endif
