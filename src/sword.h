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
				
		int getAtk();
		void usedBy(Player *player);

		// Entity method
		std::string getName();
		char getSymbol();

};
#endif
