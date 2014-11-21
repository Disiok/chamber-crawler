#ifndef ___SHADE_H___
#define ___SHADE_H___
#include <string>
#include "player.h"

class Shade: public Player {
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'S';
		static const int HP = 125;
		static const int ATK = 25;
		static const int DEF = 25;

		Shade();
};
#endif
