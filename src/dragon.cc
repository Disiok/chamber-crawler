#include "dragon.h"
using namespace std;

const string Dragon::TYPE_NAME = "Dragon";

Dragon::Dragon(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}

void Dragon::move() {}