#ifndef ___SWORD_H___
#define ___SWORD_H___
#include "equipment.h"
#include <string>
class Sword: public Equipment {
	private:
		int atk;
	public:
		static const std::string NAME_SWORD;
		static const char SYMBOL_SWORD = 'S';
		// Constructor
		Sword(Tile *tile);
		
		// Inventory method
		std::string getName();
		
		int getAtk();
		void usedBy(Player *player);
};
#endif
