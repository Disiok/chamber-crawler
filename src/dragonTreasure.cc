#include "dragonTreasure.h"
#include "dragon.h"
#include "cell.h"
#include "floor.h"
#include "tile.h"
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

const string DragonTreasure::NAME_DRAGON_TREASURE = "Dragon Treasure";

DragonTreasure::DragonTreasure(Tile *tile): Treasure(tile, GOLD_DRAGON), isGuarded(true) {
    // Spawning a Dragon adjacent to DragonTreasure
    Dragon *d = new Dragon(tile, NULL);
    vector<Cell *> spawnableCells;
    int i = getCell()->getI();
    int j = getCell()->getJ();
    // Check each side and add to vector if cell is steppable
    for (int a = -1 ; a <= 1 ; a++) {
        for (int b = -1 ; b <= 1 ; b++) {
            if (getCell()->getFloor()->getCell(i+a, j+b)->isSteppable(d)) {
                spawnableCells.push_back(getCell()->getFloor()->getCell(i+a, j+b));
            }
        }
    }

    if (spawnableCells.size() == 0) {
        return;
    } else {
        int roll = rand() % spawnableCells.size();
        Cell *cell = spawnableCells.at(roll);
        // change Tile dragon was inialized with to correct one.
        delete d;
        d = new Dragon(dynamic_cast<Tile *>(cell), this);
        cell->setEntity(d);
    }
}

DragonTreasure::DragonTreasure(Tile *tile, bool noDragon): Treasure(tile, GOLD_DRAGON), isGuarded(false) {}

bool DragonTreasure::isSteppable(Player *) {
	return !isGuarded;
}

void DragonTreasure::unlock() {
    isGuarded = false;
}

void DragonTreasure::lock() {
    isGuarded = true;
}

string DragonTreasure::getName() {
	return NAME_DRAGON_TREASURE;
}
