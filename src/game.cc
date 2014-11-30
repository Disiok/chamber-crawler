#include "game.h"
#include "floor.h"
#include "boostAtk.h"
#include "boostDef.h"
#include "woundAtk.h"
#include "woundDef.h"
#include "poisonHealth.h"
#include "restoreHealth.h"
#include "merchant.h"
#include <string>
#include <cstdlib>
#include "player.h"
#include <iostream>
using namespace std;

// Initializing static fields
const int Game::MAX_LEVEL = 5;
const string Game::DEFAULT_FLOOR = "default.floor";
Game *Game::game = NULL;
bool Game::nextFloorFlag = false;
bool Game::restartFlag = false;
bool Game::quitFlag = false;

// Static instance accessor
Game *Game::getInstance() {
	if (!game) {
		game = new Game();
		atexit(cleanup);
	}
	return game;
}

// Constructor
Game::Game(): floor(NULL), level(1), action("") {};

// Destructor
Game::~Game() {
	delete floor;
}

void Game::start(string floorFile) {
#ifdef DEBUG
	cout << "Game::start" << endl;
#endif

#ifdef SEED
	srand(SEED);
#endif
	chooseRace();
	if (floorFile != "") {
		setupFloor(floorFile);
	} else {
		setupFloor();
	}
	runGameLoop();
}

void Game::restart() {
	delete floor;
	level = 1;
	BoostAtk::resetRevealed();
    BoostDef::resetRevealed();
    WoundAtk::resetRevealed();
    WoundDef::resetRevealed();
    PoisonHealth::resetRevealed();
    RestoreHealth::resetRevealed();
	Merchant::resetHostile();
	start();
}

void Game::quit() {
	// TODO: run w. valgrind
}

void Game::signalNextFloor() {
	nextFloorFlag = true;
}

void Game::restartOrQuit() {
	while (true) {
		cout << "Restart (r) or Quit (q)?" << endl;
		string choice;
		cin >> choice;
		if (choice == "r") {
			restartFlag = true;
			break;
		} else if (choice == "q") {
			quitFlag = true;
			break;
		}
	}
}

void Game::nextFloor() {
#ifdef DEBUG
	cout << "Game::nextFloor" << endl;
#endif
	// TODO: unwind potions
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
		int atk = player->getAtk();
		int def = player->getDef();
		int hp = player->getHP();
		int gold = player->getGold();

		delete floor;
		srand(rand()%300);

		// setup floor w/o display
		floor = new Floor();
		floor->loadFromFile(DEFAULT_FLOOR);
		floor->spawn();

		Player::getInstance()->setAtk(atk);
		Player::getInstance()->setDef(def);
		Player::getInstance()->setHP(hp);
		Player::getInstance()->setGold(gold);
		display();
	}
}

void Game::setupFloor(string floorFile) {
	string file = floorFile != "" ? floorFile : DEFAULT_FLOOR;

	floor = new Floor();
	floor->loadFromFile(file);
	floor->spawn();
	display();
}

void Game::chooseRace() {
	cout << "Choose race: ";
	char race;
	cin >> race;
	Player::setRace(race);
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
	Cell *cell = parseDirection(command);
	if (cell != NULL) {
		Player::getInstance()->move(cell);
	} else {
		if (command == "u") {
			cin >> command;
			cell = parseDirection(command);
			Player::getInstance()->pickUp(cell);
		} else if (command == "a") {
			cin >> command;
			cell = parseDirection(command);
			Player::getInstance()->engage(cell);
		} else if (command == "r") {
			restartFlag = true;
		} else if (command == "q") {
			quitFlag = true;
		}
	}
}

void Game::runEnemyTurn() {
	floor->performAction();
}

void Game::cleanup() {
	delete game;
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

void Game::display() {
	floor->displayFloor();
	displayInfo();
	displayAction();
}

void Game::displayInfo() {
	cout << "Race: " << Player::getInstance()->getTypeName();
	cout << " Gold: " << Player::getInstance()->getGold();
	cout << "\t\t\t\t\t\t\tFloor " << level << endl;

	cout << "HP: " << Player::getInstance()->getHP() << endl;
	cout << "Atk: " << Player::getInstance()->getAtk() << endl;
	cout << "Def: " << Player::getInstance()->getDef() << endl;
}

void Game::displayAction() {
	// TODO: print previous action
	cout << "Action: " << action << endl;
}

void Game::addAction(string action) {
	this->action += action;
}

void Game::clearAction() {
	action = "";
}
