#include "game.h"
#include "floor.h"
#include <string>
#include <cstdlib>
#include "player.h"
#include <iostream>
using namespace std;

// Initializing static fields
const string Game::DEFAULT_FLOOR = "default.floor";
Game *Game::game = NULL;

Game *Game::getInstance() {
	if (!game) {
		game = new Game();
		atexit(cleanup);
	}
	return game;
}

// Constructor
Game::Game(): floor(0) {};

// Destructor
Game::~Game() {
	delete floor;
}


void Game::start() {
#ifdef DEBUG
	cout << "Game::start" << endl;
#endif
	chooseRace();
	setupFloor();
	runGameLoop();
}

void Game::nextFloor() {
#ifdef DEBUG
	cout << "Game::nextFloor" << endl;
#endif
	//TODO: Implement next floor logic
}

void Game::setupFloor() {
	floor = new Floor();
	floor->loadFromFile(DEFAULT_FLOOR);
	floor->spawn();
	floor->displayFloor();
}

void Game::chooseRace() {
	cout << "Choose race: ";
	char race;
	cin >> race;
	Player::setRace(race);
}

void Game::runGameLoop() {
	// TODO: Add breaking logic
	while(true) {
		runPlayerTurn();
		runEnemyTurn();
        floor->displayFloor();
	}
}

void Game::runPlayerTurn() {
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
			// TODO: Restart
		} else if (command == "q") {
			// TODO: Quit
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
