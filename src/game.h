#ifndef ___GAME_H___
#define ___GAME_H___
#include <string>

// Forward declaration
class Floor;

class Game {
	private:
		static Game *game;
		static void cleanup();
		
		Floor *floor;
		
		Game();

		void chooseRace();
		void runGameLoop();

		void runPlayerTurn();
		void runEnemyTurn();

		void setupFloor();
	public:
		static const std::string DEFAULT_FLOOR;
		static Game *getInstance();

		~Game();
		
		void start();
};
#endif
