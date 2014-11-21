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
	public:
		Entity(Tile *tile);
		virtual ~Entity() = 0;

		void destroy();
		virtual void performAction();
		virtual bool isAttacked(Character *character);
		virtual bool isPickedUp(Character *character);
		virtual bool isSteppedOn(Character *character);
		virtual bool isOccupied(Player *player);
		virtual bool isOccupied(Enemy *enemy);

};
#endif
