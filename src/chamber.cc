#include "chamber.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Chamber::Chamber(vector<Tile *>& tiles) {
    chamberTiles = tiles;
    numTiles = tiles.size();
#ifdef DEBUG
    cout<<"Chamber with "<<numTiles<<" tiles created."<<endl;
#endif
}

Tile *Chamber::getRandomTile() {
    return chamberTiles.at(rand() % numTiles);
}
