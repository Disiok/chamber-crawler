#include "drow.h"
#include "cell.h"
#include <string>
#include <iostream>
using namespace std;

const string Drow::NAME_DROW = "Drow";

Drow::Drow(Tile *tile): Player(tile, HP, ATK, DEF) {
#ifdef DEBUG
	cout << "Drow::Drow" << endl;
#endif
}

bool Drow::attackedBy(Character *other) {
    other->attack(this);
    if (isDead()) {
        killedBy(other);
    }
    return true;
}

void Drow::pickUp(Cell *cell) {
    cell->pickedUpBy(this);
}

string Drow::getName() {
	return NAME_DROW;
}
