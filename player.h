#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"
#include <string>
class Player: public Character {
	private:
		char typeIdentifier;
		std::string typeName;
};
#endif
