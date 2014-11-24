#include "orc.h"
#include <string>
using namespace std;

const string Orc::TYPE_NAME = "Orc";

Orc::Orc(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}
