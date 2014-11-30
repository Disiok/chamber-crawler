#ifndef ___NORMALTREASURE_H___
#define ___NORMALTREASURE_H___
#include "treasure.h"
class NormalTreasure: public Treasure {
	public:
		static const std::string NAME_NORMAL_TREASURE;
		static const int GOLD_NORMAL = 2;
		NormalTreasure(Tile *tile);

		// Entity method
		std::string getName();
};
#endif
