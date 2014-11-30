#ifndef ___GAME_H___
#define ___GAME_H___
#include <string>
#include <fstream>

// Forward declaration
class Floor;
class Cell;
class Inventory;

class Game {
	private:
		static const int MAX_LEVEL;
		static Game *game;
		static void cleanup();
		static bool nextFloorFlag;
		static bool restartFlag;
		static bool quitFlag;
		static std::ifstream *floorStream;
		static std::string floorFile;
		static bool defaultFloor;

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

		Cell *parseDirection(std::string direction);
		int parseInventoryIndex(std::string index);

	public:
		static const std::string DEFAULT_FLOOR;
		static Game *getInstance();

		~Game();

		void start(std::string floorFile="");
		void signalNextFloor();
		void restartOrQuit();
		void addAction(std::string action);
};
#endif
