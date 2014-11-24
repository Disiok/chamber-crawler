#include "drow.h"
#include <string>
#include <iostream>
using namespace std;

const string Drow::TYPE_NAME = "Drow";

Drow::Drow(Tile *tile): Player(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {
#ifdef DEBUG
	cout << "Drow::Drow" << endl;
#endif 
}
