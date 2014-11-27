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
	level ++;
}

void Game::setupFloor() {
	floor = new Floor();
	floor->loadFromFile(DEFAULT_FLOOR);
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
	// TODO: Add breaking logic
	while(true) {
		clearAction();
		runPlayerTurn();
		runEnemyTurn();
		display();
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
