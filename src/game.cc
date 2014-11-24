#include "game.h"
#include "floor.h"
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

}

void Game::runPlayerTurn() {

}

void Game::runEnemyTurn() {

}

void Game::cleanup() {
	delete game;
}

