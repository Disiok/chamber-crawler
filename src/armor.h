#ifndef ___ARMOR_H___
#define ___ARMOR_H___
#include "equipment.h"
class Armor: public Equipment {
	private:
		int def;
	public:
		static const char SYMBOL_ARMOR = 'A';
		Armor(Tile *tile);

		int getDef();
};
#endif
