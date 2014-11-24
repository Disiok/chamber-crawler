#ifndef ___TROLL_H___
#define ___TROLL_H___
#include <string>
#include "player.h"

class Troll: public Player {
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'T';
		static const int HP = 120;
		static const int ATK = 25;
		static const int DEF = 15;

		Troll();

		void invokeAbility();

};
#endif
