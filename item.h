#ifndef ___ITEM_H___
#define ___ITEM_H___
#include "entity.h"

class Item: public Entity {
	public:
		// Constructor & Destructor
		Item(Tile *tile);
		virtual ~Item() = 0;
};
#endif
