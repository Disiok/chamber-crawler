#include "dragonTreasure.h"
#include "dragon.h"
#include "cell.h"
#include "floor.h"
#include "tile.h"
#include <vector>
#include <cstdlib>

// temp
#include <iostream>
using namespace std;

DragonTreasure::DragonTreasure(Tile *tile): Treasure(tile, GOLD_DRAGON), isGuarded(true) {
    // Spawning a Dragon adjacent to DragonTreasure
    Dragon *d = new Dragon(tile);
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
        tile->setEntity(d);
        int roll = rand() % spawnableCells.size();
        Cell *cell = spawnableCells.at(roll);
        cell->setEntity(d);
    }
}

bool DragonTreasure::isSteppable(Player *player) {
	return !isGuarded;
}