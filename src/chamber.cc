#include "chamber.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Chamber::Chamber(vector<Cell *>& cells) {
    chamberCells = cells;
    numCells = cells.size();
#ifdef DEBUG
    cout<<"Chamber with "<<numCells<<" created."<<endl;
#endif
}

Cell *Chamber::getRandomCell() {
    return chamberCells.at(rand() % numCells);
}