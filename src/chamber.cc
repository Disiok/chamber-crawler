#include "chamber.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Chamber::Chamber(vector<Cell *>& cells) {
    chamberCells = cells;
    numCells = cells.size();
    cout<<numCells<<endl;
}

Cell *Chamber::getRandomCell() {
    return chamberCells.at(rand() % numCells);
}