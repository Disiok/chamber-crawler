#include "passage.h"

Passage::Passage(int i, int j):
	Cell(i, j, SYMBOL_PASSAGE) {}

bool Passage::isSteppable(Player *player) {
    return true;
}