#ifndef ___MERCHANTTREASURE_H___
#define ___MERCHANTTREASURE_H___
#include "treasure.h"
class MerchantTreasure: public Treasure {
	public:
		static const std::string NAME_MERCHANT_TREASURE;
		static const int GOLD_MERCHANT = 4;
		MerchantTreasure(Tile *tile);

		// Entity method
		std::string getName();
};
#endif
