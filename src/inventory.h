#ifndef ___INVENTORY_H___
#define ___INVENTORY_H___
#include "entity.h"
#include <string>

class Player;
class Character;

class Inventory: public Entity {
	public:
		Inventory(Tile *tile);
		virtual ~Inventory() = 0;
		
		virtual void usedBy(Player *player) = 0;
		virtual bool pickedUpBy(Character *character);
		virtual bool pickedUpBy(Drow *drow);
		virtual void addPickupAction();
};
#endif
