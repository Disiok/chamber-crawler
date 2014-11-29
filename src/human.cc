#include "human.h"
#include <string>
#include "cell.h"
using namespace std;

const string Human::TYPE_NAME = "Human";

Human::Human(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}

void Human::killedBy(Character *other) {
    int gold = other->calculateGoldFrom(this);
    other->setGold(other->getGold() + gold);
    getCell()->destroyEntity();

    addKilledAction(gold);
}