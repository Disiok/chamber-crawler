#ifndef ___VAMPIRE_H___
#define ___VAMPIRE_H___
#include <string>
#include "player.h"
#include "character.h"

class Vampire: public Player {
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'V';
		static const int HP = 50;
		static const int ATK = 25;
		static const int DEF = 25;

		Vampire(Tile *tile);
		void attack(Character *other);
		void attack(Dwarf *dwarf);
		void setHP(int hp);
};
#endif
