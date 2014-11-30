#include "elf.h"
#include <string>
using namespace std;

const string Elf::NAME_ELF = "Elf";

Elf::Elf(Tile *tile): Enemy(tile, HP, ATK, DEF) {}

void Elf::attack(Character *other) {
	Character::attack(other);
	Character::attack(other);
}

void Elf::attack(Drow *drow) {
	Character::attack(drow);
}

char Elf::getSymbol() {
	return SYMBOL_ELF;
}

string Elf::getName() {
	return NAME_ELF;
}
