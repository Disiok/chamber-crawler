#include "shade.h"
#include "player.h"
#include "tile.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const string Shade::TYPE_NAME = "Shade";

Shade::Shade(Tile *tile): Player(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {
#ifdef DEBUG
	cout << "Shade::Shade" << endl;
#endif
}

int Shade::getScore() {
    return ceil(1.5 * Player::getScore());
}
