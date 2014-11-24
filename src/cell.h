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
		static Cell *getInstance(int i, int j, char id);
		// Constructor & Destructor
		Cell(int i, int j, char symbol);
		virtual ~Cell() = 0;

		// Methods
		virtual bool performAction();
		virtual bool isSteppable(Player *player);
		virtual bool isSteppable(Enemy *enemy);
		virtual char getSymbol();
		void spawnEnemy();
		void spawnPotion();
		void spawnTreasure();
		void spawnStair();
		void spawnPlayer();

};
#endif
