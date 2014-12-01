#ifndef ___ENTITY_H___
#define ___ENTITY_H___
#include <string>

// Forward declarations
class Cell;
class Tile;
class Character;
class Player;
class Enemy;
class Drow;
class Goblin;

/**
 * Entity:
 * 	Spawnable on Tiles
 */
class Entity {
	protected:
		Cell *cell;
	public:
		// Constructor & destructor
		Entity(Tile *tile);
		virtual ~Entity() = 0;
		
		// Methods
		virtual void performAction();
		virtual void resetMoved();
		
		virtual bool attackedBy(Character *);
		virtual bool attackedBy(Goblin *);

		virtual bool pickedUpBy(Character *);
		virtual bool pickedUpBy(Drow *);

		virtual bool steppedOnBy(Character *);

		virtual bool isSteppable(Player *);
		virtual bool isSteppable(Enemy *);
		
		// Accessors
		virtual Cell *getCell();
		virtual char getSymbol() = 0;
		virtual std::string getName() = 0;

		// Mutator
		void setCell(Cell *);
};
#endif
