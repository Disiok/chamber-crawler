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
	}
}

void Game::runPlayerTurn() {
	cout << "Enter command: ";
	string command;
	cin >> command;
	int direction = parseDirection(command);
	if (direction != -1) {
		Player::getInstance()->move(direction);
	} else {
		if (command == "u") {
			cin >> command;
			direction = parseDirection(command);
			Player::getInstance()->pickUp(direction);
		} else if (command == "a") {
			cin >> command;
			direction = parseDirection(command);
			Player::getInstance()->engage(direction);
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
 * 		789
 * 		456
 * 		123
 */
int Game::parseDirection(string direction) {
	if (direction == "no") {
		return 8;
	} else if (direction == "so") {
		return 2;
	} else if (direction == "ea") {
		return 6;
	} else if (direction == "we") {
		return 4;
	} else if (direction == "ne") {
		return 9;
	} else if (direction == "nw") {
		return 7;
	} else if (direction == "se") {
		return 3;
	} else if (direction == "sw") {
		return 1;
	} else if (direction == "st") {
		return 5;
	} else {
		return -1;
	}
}
