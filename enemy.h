#ifndef ___ENEMY_H___
#define ___ENEMY_H___
#include "character.h"
#include <string>
class Enemy: public Character {
	private:
		char typeIdentifier;
		std::string typeName;
		float spawnRate;
	public:
};
#endif
