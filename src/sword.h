#ifndef ___SWORD_H___
#define ___SWORD_H___
#include "equipment.h"
class Sword: public Equipment {
	private:
		int atk;
	public:
		static const char SYMBOL_SWORD = 'S';
		Sword(Tile *tile);
		
		int getAtk();
};
#endif
