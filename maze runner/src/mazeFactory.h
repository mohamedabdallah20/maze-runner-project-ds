#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class mazeFactory {
    ifstream maze;
	int width,height;
	string * mazeS;
public:
   	 mazeFactory();
	 ~mazeFactory();
};


