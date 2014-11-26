#ifndef ___TILE_H___
#define ___TILE_H___
#include "cell.h"

// Forward declaration
class Entity;
class Character;
class Player;
class Enemy;

class Tile: public Cell {
	public:
		static const char SYMBOL_TILE = '.';

		// Constructor
		Tile(int i, int j, Floor* floor);

		// Tile methods
		void spawnEnemy();
		void spawnPotion();
		void spawnTreasure();
		void spawnStair();
		void spawnPlayer();

		// Override methods
		bool isSteppable(Player *player);
		bool isSteppable(Enemy *enemy);
};
#endif
