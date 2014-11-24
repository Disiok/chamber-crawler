#include "shade.h"
#include <string>
#include "player.h"
#include "tile.h"
#include <iostream>
using namespace std;

const string Shade::TYPE_NAME = "Shade";

Shade::Shade(Tile *tile): Player(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {
#ifdef DEBUG
	cout << "Shade::Shade" << endl;
#endif
}
