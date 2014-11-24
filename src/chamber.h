#ifndef ___CHAMBER_H___
#define ___CHAMBER_H___
#include <vector>

// Forward declaration
class Tile;

class Chamber {
	private:
		std::vector<Tile *> chamberTiles;
		int numTiles;
	public:
		Chamber(std::vector<Tile *>& tiles);
		Tile *getRandomTile();
};
#endif
