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
		static bool nextFloorFlag;
		static bool restartFlag;
		static bool quitFlag;

		Floor *floor;
		int level;
		std::string action;

		Game();

		void chooseRace();
		void runGameLoop();

		void runPlayerTurn();
		void runEnemyTurn();

		void setupFloor();
		void nextFloor();
		void restart();
		void quit();

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
		void signalNextFloor();
		void signalRestart();
		void signalQuit();
		void addAction(std::string action);
};
#endif
