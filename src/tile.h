#ifndef ___TILE_H___
#define ___TILE_H___
#include "cell.h"

// Forward declaration
class Entity;
class Character;
class Player;
class Enemy;

class Tile: public Cell {
	private:
		Entity *entity;
	public:
		static const char SYMBOL_TILE = '.';

		// Constructor
		Tile(int i, int j);

		// Methods
		void clearEntity();
		void destroyEntity();
		void setEntity(Entity *entity);	

		bool steppedOnBy(Character *other);
		bool pickedUpBy(Character *other);
		bool attackedBy(Character *other);
		
		bool isSteppable(Player *player);
		bool isSteppable(Enemy *enemy);
};
#endif
