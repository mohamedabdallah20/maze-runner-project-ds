#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class node{
public:
	int x, y;
	node *up,*down,*right,*left;
	node();
	~node();
};
class mazeFactory {
	node *root;
    ifstream maze;
	int width,height;
	char ** mazeS;
	int ** intmaze;
	bool **visited;
	int x,y;
	void graph(node*,bool,bool,bool,bool);
	void coutgraph(node *);
public:
	void getgraph();
   	 mazeFactory();
	 ~mazeFactory();
};


