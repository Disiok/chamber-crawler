#ifndef ___INVENTORY_H___
#define ___INVENTORY_H___
#include "entity.h"
#include <string>
class Inventory: public Entity {
	public:
		Inventory(Tile *tile, char symbol);
		std::string getName();
};
#endif
