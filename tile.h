#ifndef ___TILE_H___
#define ___TILE_H___
#include "cell.h"

// Forward declaration
class Entity;

class Tile: public Cell {
	private:
		Entity *entity;
	public:
		void clearEntity();
		void setEntity(Entity *entity);	
};
#endif
