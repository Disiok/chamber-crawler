#ifndef ___ELF_H___
#define ___ELF_H___
#include "enemy.h"
class Elf: public Enemy {
	public:
		static const std::string NAME_ELF;
		static const char SYMBOL_ELF = 'E';
		static const int HP = 140;
		static const int ATK = 30;
		static const int DEF = 10;
		Elf(Tile *tile);

		void attack(Character *other);
		void attack(Drow *drow);

		// Entity methods
		char getSymbol();
		std::string getName();
};
#endif
