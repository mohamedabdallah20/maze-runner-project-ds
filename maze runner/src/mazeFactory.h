#include <string>
using namespace std;
class mazeFactory {
	int width,height;
	string maze;
	void setheight();
	void setwidth();
public:
	void getheight();
	void getwidth();
	mazeFactory();
	 ~mazeFactory();
};


