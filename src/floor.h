#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>

// Forward declaration
class Cell;
class Chamber;

class Floor {
	public:
		static const int MAX_CHAMBERS = 5;
		static const int MAX_ROW = 25;
		static const int MAX_COLUMN = 79;
		
		Floor();
		~Floor();

		void loadFromFile(std::string fileName);
	private:
		Cell ***map;
		Chamber *chambers[MAX_CHAMBERS];
		
};
#endif
