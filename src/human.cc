#include "human.h"
#include <string>
#include "cell.h"
#include "goblin.h"
#include <iostream>
using namespace std;

const string Human::NAME_HUMAN = "Human";

Human::Human(Tile *tile): Enemy(tile, HP, ATK, DEF) {}

void Human::killedBy(Character *other) {
    int gold = other->calculateGoldFrom(this);
    other->setGold(other->getGold() + gold);
    getCell()->destroyEntity();

    addKilledAction(gold);
}

void Human::killedBy(Goblin *goblin) {
    int gold = goblin->calculateGoldFrom(this);
    goblin->setGold(goblin->getGold() + gold);
    getCell()->destroyEntity();

    addKilledAction(gold);
}

char Human::getSymbol() {
	return SYMBOL_HUMAN;
}

string Human::getName() {
	return NAME_HUMAN;
}
