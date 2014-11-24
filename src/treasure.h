#ifndef ___TREASURE_H___
#define ___TREASURE_H___
#include "entity.h"
class Treasure: public Entity {
	private:
		const int gold;
	public:
		static const char SYMBOL_TREASURE = 'G';
		
		Treasure(Tile *tile, int gold);
		virtual ~Treasure() = 0;
		
		virtual bool isSteppable(Player *player);
		virtual bool isSteppable(Enemy *enemy);
		virtual bool steppedOnBy(Character *character);
};
#endif
