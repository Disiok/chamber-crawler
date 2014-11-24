#include "human.h"
#include <string>
using namespace std;

const string Human::TYPE_NAME = "Human";

Human::Human(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}


