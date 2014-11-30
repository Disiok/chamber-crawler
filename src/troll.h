#ifndef ___TROLL_H___
#define ___TROLL_H___
#include <string>
#include "player.h"

// Forward declaration
class Tile;

class Troll: public Player {
	public:
		static const std::string NAME_TROLL;
		static const char SYMBOL_TROLL = 'T';
		static const int HP = 120;
		static const int ATK = 25;
		static const int DEF = 15;

		Troll(Tile *tile);

		void invokeAbility();

		// Entity method
		std::string getName();
};
#endif
