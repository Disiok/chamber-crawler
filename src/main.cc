#include <iostream>
#include <ncurses.h>
#include "game.h"
using namespace std;

int main(int argc, char* argv[]) {
    initscr();
    cbreak();
                     noecho();
    keypad(stdscr, TRUE);
#ifdef DEBUG
	cout << "Main function" << endl;
#endif
	Game *game = Game::getInstance();
    // Read floor from specified file.
    if (argc > 1) {
        game->start(argv[1]);
    } else {
	    game->start("");
    }
    endwin();
}
