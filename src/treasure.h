#ifndef ___TREASURE_H___
#define ___TREASURE_H___
#include "entity.h"
class Treasure: public Entity {
	private:
		const int gold;

		void addGoldAction(int gold);
	public:
		static const char SYMBOL_TREASURE = 'G';
		
		// Constructor & destructor
		Treasure(Tile *tile, int gold);
		virtual ~Treasure() = 0;
		
		// Entity methods
		bool isSteppable(Player *);
		bool steppedOnBy(Character *);

};
#endif
