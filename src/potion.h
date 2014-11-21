#ifndef ___POTION_H___
#define ___POTION_H___
#include "player.h"
class Potion: public Player {
	private:
		Player *player;
	public:
		Potion(Tile *tile);

		// Delegating Player methods
		void move(int direction);
		void pickUp(int direction);
		void killedBy(Character *other);

		// Delegating Character methods
		void attack(Character *other);
		bool attackedBy(Character *other);
		void move();
		void killedBy(Character *other);

		bool isDead();

		int getHP();
		int getAtk();
		int getDef();
		int getGold();
		
		void setHP(int hp);
		void setAtk(int atk);
		void setDef(int def);
		void setGold(int gold);

		// Delegating Entity methods
		Tile *getTile();

};
#endif
