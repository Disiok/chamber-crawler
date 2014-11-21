#include <iostream>
#include "game.h"
using namespace std;

int main() {
#ifdef DEBUG
	cout << "Main function" << endl;
#endif
	Game *game = Game::getInstance();
	game->start();
}
