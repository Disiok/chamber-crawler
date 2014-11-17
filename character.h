#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___
class Character {
	private:
		int healthPoint;
		int attack;
		int defense;

	public:
		Character(int healthPoint, int attack, int defense);
		virtual ~Character() = 0;
};
#endif
