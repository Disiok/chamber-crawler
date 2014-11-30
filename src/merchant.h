#ifndef ___MERCHANT_H___
#define ___MERCHANT_H___
#include "enemy.h"

class Goblin;

class Merchant: public Enemy {
	private:
		static bool isHostile;
		void addKilledAction();
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'M';
		static const int HP = 30;
		static const int ATK = 70;
		static const int DEF = 5;
		Merchant(Tile *tile);
		static void resetHostile();

		bool attackedBy(Character *other);
		bool isPlayerNearby();

		void killedBy(Character *other);
		void killedBy(Goblin *goblin);
};
#endif
