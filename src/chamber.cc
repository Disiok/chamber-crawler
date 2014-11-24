#include "chamber.h"
#include "tile.h"
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
	Tile *tile = chamberTiles.at(rand() % numTiles);
	while (tile->hasEntity()) {
		tile = chamberTiles.at(rand() % numTiles);
	}
	return tile;
}
