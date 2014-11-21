#include "floor.h"
#include "chamber.h"
#include <fstream>
#include <iostream>
#include "cell.h"
#include <string>
using namespace std;

Floor::Floor() {
	map = NULL;
	for (int i = 0; i < MAX_CHAMBERS; i ++) {
		chambers[i] = NULL;
	}
}

Floor::~Floor() {
	if (map) {
		for (int i = 0; i < MAX_ROW; i ++) {
			for (int j = 0; j < MAX_COLUMN; j ++) {
				delete map[i][j];
			}
			delete map[i];
		}
		delete map;
	}
	for (int i = 0; i < MAX_CHAMBERS; i ++) {
		delete chambers[i];
	}

}

void Floor::loadFromFile(string fileName) {
#ifdef DEBUG
	cout << "Floor::loadFromFile(\"" << fileName << "\")" << endl;
#endif
	// TODO: Add file parsing logic
}
