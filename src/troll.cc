#include "troll.h"
#include <iostream>
#include <string>
using namespace std;

const string Troll::TYPE_NAME = "Troll";

Troll::Troll(): Player(NULL, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {
#ifdef DEBUG
	cout << "Troll::Troll" << endl;
#endif
};

void Troll::invokeAbility() {
	// TODO: Implement max health
	setHP(getHP() + 5);
}
