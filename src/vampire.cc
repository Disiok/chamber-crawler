#include "vampire.h"
#include <iostream>
#include <string>
using namespace std;

const string Vampire::TYPE_NAME = "Vampire";

Vampire::Vampire(): Player(NULL, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {
#ifdef DEBUG
	cout << "Vampire::Vampire" << endl;
#endif 
}

void Vampire::attack(Character *other) {
	Character::attack(other);
	
	// Life steal
	setHP(getHP() + 5);
}
