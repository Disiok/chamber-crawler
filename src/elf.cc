#include "elf.h"
#include <string>
using namespace std;

const string Elf::TYPE_NAME = "Elf";

Elf::Elf(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}