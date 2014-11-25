#ifndef ___ENTITY_H___
#define ___ENTITY_H___

// Forward declarations
class Tile;
class Character;
class Player;
class Enemy;

/**
 * Entity:
 * 	Spawnable on Tiles
 */
class Entity {
	private:
		Tile *tile;
		char symbol;
	public:
		Entity(Tile *tile, char symbol);
		virtual ~Entity() = 0;

		void destroy();
		virtual void performAction();
		virtual bool attackedBy(Character *character);
		virtual bool pickedUpBy(Character *character);
		virtual bool steppedOnBy(Character *character);
		virtual bool isSteppable(Player *player);
		virtual bool isSteppable(Enemy *enemy);

		Tile *getTile();
		char getSymbol();
		
		void setTile(Tile *tile);
		


};
#endif
