#ifndef ___GAME_H___
#define ___GAME_H___
#include <string>
#include "cell.h"

// Forward declaration
class Floor;

class Game {
	private:
		static const int MAX_LEVEL;
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

		void setupFloor(std::string floorFile = "");
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

		void start(std::string floorFile = "");
		void signalNextFloor();
		void restartOrQuit();
		void addAction(std::string action);
};
#endif
