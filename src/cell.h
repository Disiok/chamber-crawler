#ifndef ___CELL_H___
#define ___CELL_H___

// Forward declaration
class Character;
class Entity;
class Player;
class Enemy;
class Floor;
class Drow;
class Goblin;

class Cell {
	private:
		// Coordinates
		int i;
		int j;

		// Representation
		char symbol;

		Floor *floor;
	protected:
		Entity *entity;
	public:
		static Cell *getInstance(int i, int j, char id, Floor *floor);
		// Constructor & Destructor
		Cell(int i, int j, char symbol, Floor *floor);
		virtual ~Cell() = 0;

		// Methods
		virtual void performAction();
		virtual void resetMoved();
		virtual bool isSteppable(Player *player);
		virtual bool isSteppable(Enemy *enemy);

		bool hasEntity();
		void clearEntity();
		void destroyEntity();
		Entity *getEntity();
		void setEntity(Entity *entity);

		bool steppedOnBy(Character *other);
		bool pickedUpBy(Character *other);
		bool pickedUpBy(Drow *drow);
		bool attackedBy(Character *other);
		bool attackedBy(Goblin *goblin);

		char getSymbol();
		Floor *getFloor();
		int getI();
		int getJ();

};
#endif
