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

		// Tile methods
		void clearEntity();
		void destroyEntity();
		void setEntity(Entity *entity);	

		void spawnEnemy();
		void spawnPotion();
		void spawnTreasure();
		void spawnStair();
		void spawnPlayer();

		
		bool steppedOnBy(Character *other);
		bool pickedUpBy(Character *other);
		bool attackedBy(Character *other);
		
		// Override methods
		bool isSteppable(Player *player);
		bool isSteppable(Enemy *enemy);
		char getSymbol();
};
#endif
