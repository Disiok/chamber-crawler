#include "floor.h"
#include "chamber.h"
#include <fstream>
#include <iostream>
#include "cell.h"
#include <string>
using namespace std;

Floor::Floor() {
	for (int i = 0; i < MAX_ROW; i ++) {
		for (int j = 0; j < MAX_COLUMN; j ++) {
			map[i][j] = NULL;
		}
	}
	for (int i = 0; i < MAX_CHAMBERS; i ++) {
		chambers[i] = NULL;
	}
}

Floor::~Floor() {
	for (int i = 0; i < MAX_ROW; i ++) {
		for (int j = 0; j < MAX_COLUMN; j ++) {
			delete map[i][j];
		}
	}
	for (int i = 0; i < MAX_CHAMBERS; i ++) {
		delete chambers[i];
	}
}

/* *
 * floodChamber
 * Gets all the cells in the chamber by flooding it start from (i, j)
 * Marks off flooded tiles in the rows parameter, and returns a new Chamber
 */
void Floor::floodChamber(int i, int j, string (*rows)[MAX_ROW], std::vector<Cell *> *cells) {
	cells->push_back(map[i][j]);
	rows[i][j] = '~';
	if (i > 0) {
		if (map[i-1][j]->getSymbol() == '.') {
			floodChamber(i-1, j, rows, cells);
		}
	}
	if (j > 0) {
		if (map[i][j-1]->getSymbol() == '.') {
			floodChamber(i, j-1, rows, cells);
		}
	}
	if (i < MAX_ROW) {
		if (map[i+1][j]->getSymbol() == '.') {
			floodChamber(i+1, j, rows, cells);
		}
	}
	if (j < MAX_COLUMN) {
		if (map[i][j+1]->getSymbol() == '.') {
			floodChamber(i, j+1, rows, cells);
		}
	}
}

void Floor::loadFromFile(string fileName) {
#ifdef DEBUG
	cout << "Floor::loadFromFile(\"" << fileName << "\")" << endl;
#endif
	// 'rows' stores the floor to be later flooded to create chambers
	string rows[MAX_ROW];
	string line;
	ifstream ifs(fileName.c_str());
	for (int i = 0; i < MAX_ROW; i ++) {
		getline(ifs, line);
		rows[i] = line;
		for (int j = 0; j < MAX_COLUMN; j ++) {
			map[i][j] = Cell::getInstance(i, j, line[j]);
#ifdef DEBUG
			cout << line[j];
#endif
		}
#ifdef DEBUG
		cout << endl;
#endif
	}
	// Going through every floor tile and flooding each chamber
	int numChambers = 0;
	for (int i = 0 ; i < MAX_ROW && numChambers < MAX_CHAMBERS; i++) {
		for (int j = 0 ; j < MAX_COLUMN && numChambers < MAX_CHAMBERS; j++) {
			if (map[i][j]->getSymbol() == '.') {
				vector<Cell *> cells;
				floodChamber(i, j, &rows, &cells);
				chambers[numChambers] = new Chamber(cells);
			}
		}
	}
}

void Floor::displayFloor() {
#ifdef DEBUG
	cout << "Floor::displayFloor" << endl;
#endif

	for (int i = 0; i < MAX_ROW; i ++) {
		for (int j = 0; j < MAX_COLUMN; j ++) {
			if (map[i][j]) {
				cout << map[i][j]->getSymbol();
			} else {
				cout << ' ';
			}
		}
		cout << endl;
	}

}

void Floor::spawn() {

}
