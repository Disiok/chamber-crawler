#ifndef ___CELL_H___
#define ___CELL_H___

// Forward declaration
class Player;
class Enemy;

class Cell {
	private:
		// Coordinates
		int i;
		int j;

		// Representation
		char symbol;
	public:
		// Constructor & Destructor
		Cell(int i, int j, char symbol);
		virtual ~Cell() = 0;
		
		// Methods
		virtual bool isOccupied(Player *player);
		virtual bool isOccupied(Enemy *enemy);

};
#endif