#include <string>
#include "mazeFactory.h"
using namespace std;

class DFS {
 public:
	int width,height;
	string * maze;
	mazeFactory MF;
	DFS();
    ~DFS();
};
