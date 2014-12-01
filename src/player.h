#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"
#include <string>

// Forward declarations
class Sword;
class Armor;
class Inventory;
class Tile;
/**
 * Player:
 * 	controllable Character
 */
class Player: public Character {
	public:
		static const int MAX_INVENTORY = 5;
		static const char SYMBOL_PLAYER = '@';

		static bool setRace(char);
		static void spawn(Tile *);
       		static Player *getInstance();
        	static void setInstance(Player *);
		static void cleanup();


		// Constructor & destructor
		Player(Tile *tile, int hp, int atk, int def);
		virtual ~Player() = 0;
		
		// Player methods
		virtual bool pickUp(Cell *);
		virtual bool engage(Cell *);

		virtual void equip(Sword *);
		virtual void equip(Armor *);
		virtual bool useInventory(int index);
		virtual void addInventory(Inventory *);
		
		virtual Player *getBarePlayer();
		virtual int getScore();
		virtual Inventory *getInventoryAt(int index);
		virtual Sword *getSword();
		virtual Armor *getArmor();

		// Character methods
		bool move(Cell *);
		bool attackedBy(Character *);
		void killedBy(Character *);
		void addAttackAction(Character *other, int damage);
		void addMissAction(Character *);

		int getAtk();
		int getDef();

		// Entity methods
		char getSymbol();

		
	private:
		static Player *curPlayer;
		static char race;
		
		// Player fields
		Sword *sword;
		Armor *armor;
		Inventory *inventory[MAX_INVENTORY];
};
#endif
