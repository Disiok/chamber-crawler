#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"
#include "tile.h"
#include <string>

// Forward declarations
class Sword;
class Armor;
class Inventory;
/**
 * Player:
 * 	controllable Character
 */
class Player: public Character {
	public:
		static const int MAX_INVENTORY = 5;
		static const char SYMBOL_PLAYER = '@';

		static void setRace(char race);
		static void spawn(Tile *tile);
       		static Player *getInstance();
        	static void setInstance(Player *p);

		Player(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const std::string typeName);
		virtual ~Player() = 0;

		virtual void move(Cell *cell);
		virtual void pickUp(Cell *cell);
		virtual void engage(Cell *cell);
		virtual void killedBy(Character *other);
		bool isSteppable(Player *player);
		virtual Player *getBarePlayer();

		virtual int getScore();
		virtual bool attackedBy(Character *other);
		void addAttackAction(Character *other, int damage);
		void addMissAction(Character *other);

		int getAtk();
		int getDef();

		Inventory *getInventoryAt(int index);
		Sword *getSword();
		Armor *getArmor();

		virtual void equip(Sword *sword);
		virtual void equip(Armor *armor);
		virtual void useInventory(int index);
		virtual void addInventory(Inventory *inventory);
	private:
		static Player *curPlayer;
		static char race;

		static void cleanup();

		Sword *sword;
		Armor *armor;
		Inventory *inventory[MAX_INVENTORY];
};
#endif
