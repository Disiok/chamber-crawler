#include "player.h"
#include "goblin.h"
#include <string>
#include <iostream>
using namespace std;

const string Goblin::TYPE_NAME = "Goblin";

Goblin::Goblin(): Player(NULL, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {
#ifdef DEBUG
	cout << "Goblin::Goblin" << endl;
#endif
}
