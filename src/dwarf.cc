#include "dwarf.h"
#include <string>
using namespace std;

const string Dwarf::TYPE_NAME = "Dwarf";

Dwarf::Dwarf(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}