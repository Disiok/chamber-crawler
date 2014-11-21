#ifndef ___ENEMY_H___
#define ___ENEMY_H___
#include "character.h"
#include <string>

/**
 * Enemy:
 * 	uncontrollable Character
 */
class Enemy: public Character {
	private:
	
	public:
		void move();
		void performAction();
		void die();
		bool isAttacked(Character *character);
};
#endif
