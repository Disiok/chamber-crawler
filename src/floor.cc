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

void Floor::loadFromFile(string fileName) {
#ifdef DEBUG
	cout << "Floor::loadFromFile(\"" << fileName << "\")" << endl;
#endif
	string line;
	ifstream ifs(fileName.c_str());
	for (int i = 0; i < MAX_ROW; i ++) {
		getline(ifs, line);
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
