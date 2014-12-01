#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <fstream>
#include <vector>

// Forward declaration
class Cell;
class Tile;
class Chamber;

class Floor {
	public:
		static const int MAX_CHAMBERS = 5;
		static const int MAX_ROW = 25;
		static const int MAX_COLUMN = 79;
		static const int NUM_GOLD = 10;
		static const int NUM_POTION = 10;
		static const int NUM_ENEMY = 20;
		static const int NUM_EQUIP = 10;

		Floor();
		~Floor();

		void loadFromFile(std::ifstream *floorStream);
		void displayFloor();
		void performAction();
		void resetMoved();
		void spawn();
        Cell *getCell(int i, int j);
	private:
		Cell *map[MAX_ROW][MAX_COLUMN];
		Chamber *chambers[MAX_CHAMBERS];

		void floodChamber(int i, int j, std::string (*rows)[MAX_ROW], std::vector<Tile *> *tiles);
		Chamber *getRandomChamber();
		Tile *getRandomTile();
};
#endif
