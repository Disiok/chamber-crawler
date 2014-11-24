#ifndef ___ELF_H___
#define ___ELF_H___
#include "enemy.h"
class Elf: public Enemy {
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'E';
		static const int HP = 140;
		static const int ATK = 30;
		static const int DEF = 10;
		Elf(Tile *tile);
};
#endif
