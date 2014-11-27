#ifndef ___GAME_H___
#define ___GAME_H___
#include <string>
#include "cell.h"

// Forward declaration
class Floor;

class Game {
	private:
		static Game *game;
		static void cleanup();

		Floor *floor;
		int level;
		std::string action;

		Game();

		void chooseRace();
		void runGameLoop();

		void runPlayerTurn();
		void runEnemyTurn();

		void setupFloor();

		void display();
		void displayInfo();
		void displayAction();
		void clearAction();
	public:
		static const std::string DEFAULT_FLOOR;
		static Game *getInstance();
		Cell *parseDirection(std::string direction);

		~Game();

		void start();
		void nextFloor();
		void addAction(std::string action);
};
#endif
