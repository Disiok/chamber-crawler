#ifndef ___ARMOR_H___
#define ___ARMOR_H___
#include "equipment.h"
#include <string>

class Player;

class Armor: public Equipment {
	private:
		int def;
	public:
		static const std::string NAME_ARMOR;
		static const char SYMBOL_ARMOR = 'A';
		Armor(Tile *tile);

		int getDef();

		void usedBy(Player *player);
		std::string getName();
};
#endif
