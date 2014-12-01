#include "game.h"
#include "floor.h"
#include "cell.h"
#include "player.h"

// Potions
#include "boostAtk.h"
#include "boostDef.h"
#include "woundAtk.h"
#include "woundDef.h"
#include "poisonHealth.h"
#include "restoreHealth.h"

// Specific
#include "merchant.h"
#include "inventory.h"
#include "sword.h"
#include "armor.h"

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

// Initializing static fields
const int Game::MAX_LEVEL = 5;
const string Game::DEFAULT_FLOOR = "default.floor";
Game *Game::game = NULL;

// Static instance accessor
Game *Game::getInstance() {
	if (!game) {
		game = new Game();
		atexit(cleanup);
	}
	return game;
}

// Constructor
Game::Game(): floor(NULL), level(1), action("") {
	nextFloorFlag = false;
	restartFlag = false;
	quitFlag = false;
	floorStream = NULL;
	floorFile = "";
	defaultFloor = true;
};

// Destructor
Game::~Game() {
	delete floor;
	delete floorStream;
}

void Game::start(string floorFile) {
#ifdef DEBUG
	cout << "Game::start" << endl;
#endif

#ifdef SEED
	srand(SEED);
#else
	srand(time(NULL));
#endif
	this->floorFile = floorFile;
	if (floorFile == "") {
		floorStream = new ifstream(DEFAULT_FLOOR.c_str());
	} else {
		defaultFloor = false;
		floorStream = new ifstream(floorFile.c_str());
	}
	chooseRace();
	setupFloor();
	runGameLoop();
}

void Game::restart() {
	delete floor;
	delete floorStream;
	level = 1;
	BoostAtk::resetRevealed();
    BoostDef::resetRevealed();
    WoundAtk::resetRevealed();
    WoundDef::resetRevealed();
    PoisonHealth::resetRevealed();
    RestoreHealth::resetRevealed();
	Merchant::resetHostile();
	Player::cleanup();
	start(floorFile);
}

void Game::quit() {
	// Intentionally blank
}

void Game::signalNextFloor() {
	nextFloorFlag = true;
}

void Game::restartOrQuit() {
	string flush;
	getline(cin, flush);
	while (true) {
		cout << "Restart (r) or Quit (q)?" << endl;
		string choice;
		getline(cin, choice);
		if (tolower(choice[0]) == 'r') {
			restartFlag = true;
			break;
		} else if (tolower(choice[0]) == 'q') {
			quitFlag = true;
			break;
		}
	}
}

void Game::nextFloor() {
#ifdef DEBUG
	cout << "Game::nextFloor" << endl;
#endif
	level ++;
	if (level > MAX_LEVEL) {
		cout << endl;
		cout << "You are victorious! Congratulations, brave venturer." << endl;
		cout << "Your score is: " << Player::getInstance()->getScore() << endl;
		cout << endl;
		restartOrQuit();
	} else {
		// Carry over stats for next floor.
		Player *player = Player::getInstance()->getBarePlayer();
		Player::setInstance(player);

		delete floor;

		// setup floor
		floor = new Floor();
		floor->loadFromFile(floorStream);
		if (defaultFloor) {
			floor->spawn();
		}
		addAction("Entered a new floor!");
		display();
	}
}

void Game::setupFloor() {
	floor = new Floor();
	floor->loadFromFile(floorStream);
	if (defaultFloor) {
		floor->spawn();
	}
	display();
}

void Game::chooseRace() {
	cout << "Choose race: ";
	string race;
	getline(cin, race);
	while (!Player::setRace(toupper(race[0]))) {
		cout << "Invalid input, please try again: ";
		cin >> race;
	}
}

void Game::runGameLoop() {
	while(true) {
		// These clauses are seperated as after calling nextFloor it is possible to trigger the other flags
		if (nextFloorFlag) {
			nextFloorFlag = false;
			nextFloor();
		}
		if (restartFlag) {
			restartFlag = false;
			restart();
			break;
		}
		if (quitFlag) {
			cout << endl;
			cout << "Farewell, adventurer."<<endl;
			quit();
			break;
		}
		clearAction();
		runPlayerTurn();
		runEnemyTurn();
		// Show board if game continues as normal, else clear action text for new floor
		if (!nextFloorFlag && !restartFlag && !quitFlag) {
			if (action == "") {
				addAction("Nothing happened. ");
			}
			display();
		} else {
			clearAction();
		}
	}
}

void Game::runPlayerTurn() {
	Player::getInstance()->invokeAbility();

	cout << "Enter command: ";
	string command;
	cin >> command;
	bool validCommand = false;
	while (!validCommand) {
	Cell *cell = parseDirection(command);
	if (cell != NULL) {
		//nextFloorFlag = true;
		validCommand = Player::getInstance()->move(cell);
		if (validCommand) {
			addAction("PC moves " + parseLongDirection(command) + ". ");
		}
	} else {
		if (command == "u") {
			cin >> command;
			cell = parseDirection(command);
			if (cell) {
				validCommand = Player::getInstance()->pickUp(cell);
			} else {
#ifdef DLC
				int inventoryIndex = parseInventoryIndex(command);
				if (inventoryIndex != -1) {
					validCommand = Player::getInstance()->useInventory(inventoryIndex);
				}
#endif
			}
		} else if (command == "a") {
			cin >> command;
			cell = parseDirection(command);
			if (cell) {
				validCommand = Player::getInstance()->engage(cell);
			}
		} else if (command == "r") {
			restartFlag = true;
			validCommand = true;
		} else if (command == "q") {
			quitFlag = true;
			validCommand = true;
		}
	}
	if (!validCommand) {
		cout << "Invalid input, please try again: ";
		cin >> command;
	}
	}
}

void Game::runEnemyTurn() {
	floor->performAction();
}

void Game::cleanup() {
	delete game;
	game = NULL;
}

/**
 * parseDirection:
 * 	Helper function to convert from command to numpad representation of direction:
 */
Cell *Game::parseDirection(string direction) {
	int i = Player::getInstance()->getCell()->getI();
	int j = Player::getInstance()->getCell()->getJ();
	if (direction == "no") {
		return floor->getCell(i-1, j);
	} else if (direction == "so") {
		return floor->getCell(i+1, j);
	} else if (direction == "ea") {
		return floor->getCell(i, j+1);
	} else if (direction == "we") {
		return floor->getCell(i, j-1);
	} else if (direction == "ne") {
		return floor->getCell(i-1, j+1);
	} else if (direction == "nw") {
		return floor->getCell(i-1, j-1);
	} else if (direction == "se") {
		return floor->getCell(i+1, j+1);
	} else if (direction == "sw") {
		return floor->getCell(i+1, j-1);
	} else {
		return NULL;
	}
}

int Game::parseInventoryIndex(string index) {
	istringstream iss(index);
	int i;
	if (iss >> i) {
		if (i >= 1 && i <= Player::MAX_INVENTORY) {
			return i - 1;
		} else {
			return -1;
		}
	} else {
		return -1;
	}
}
string Game::parseLongDirection(string direction) {
	if (direction == "no") {
		return "Noth";
	} else if (direction == "so") {
		return "South";
	} else if (direction == "ea") {
		return "East";
	} else if (direction == "we") {
		return "West";
	} else if (direction == "ne") {
		return "North East";
	} else if (direction == "nw") {
		return "North West";
	} else if (direction == "se") {
		return "South East";
	} else if (direction == "sw") {
		return "South West";
	} else {
		return "Nowhere";
	}
}
void Game::display() {
	floor->displayFloor();
	displayInfo();
	displayAction();
}

void Game::displayInfo() {
	cout << "Race: " << Player::getInstance()->getName();
	cout << " Gold: " << Player::getInstance()->getGold();
	cout << "\t\t\t\t\t\t\tFloor " << level << endl;

	cout << "HP: " << Player::getInstance()->getHP() << endl;
	cout << "Atk: " << Player::getInstance()->getAtk();
	Sword *sword = Player::getInstance()->getSword();
	if (sword) {
		cout << "(" << sword->getName() << ")";
	} 
	cout << endl;
	cout << "Def: " << Player::getInstance()->getDef();
	Armor *armor = Player::getInstance()->getArmor();
 	if (armor) {
		cout << "(" << armor->getName() << ")";
	}	
	cout << endl;
#ifdef DLC
	cout << "Inventory: ";
	for (int i = 0; i < Player::MAX_INVENTORY; i ++) {
		Inventory *inventory = Player::getInstance()->getInventoryAt(i);
		cout <<"[" << i+1 << ". ";
		if (inventory) {
			cout << inventory->getName();
		} else {
			cout << "\t";
		}
		cout << "]";
	}
	cout << endl;
#endif
	
}

void Game::displayAction() {
	cout << "Action: " << action << endl;
}

void Game::addAction(string action) {
	this->action += action;
}

void Game::clearAction() {
	action = "";
}
