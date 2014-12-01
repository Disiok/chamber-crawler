#ifndef ___DWARF_H___
#define ___DWARF_H___
#include "enemy.h"
class Dwarf: public Enemy {
	public:
		static const std::string NAME_DWARF;
		static const char SYMBOL_DWARF = 'D';
		static const int HP = 100;
		static const int ATK = 20;
		static const int DEF = 30;
		Dwarf(Tile *tile);
        bool attackedBy(Character *other);

	// Entity methods
	char getSymbol();
	std::string getName();
};
#endif
