
#include "mazeFactory.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
mazeFactory::mazeFactory() {
width=0;
height=0;
int i=0;
    maze.open("maze.text");
    if(maze.is_open()){
    	maze>>width>>height;
    	mazeS=new string[height*2+2];
    	while(getline(maze,mazeS[i])){
    		//cout<<mazeS[i]<<"\n";
    		i++;
    	}
    	maze.close();
    }
    else{
    	cout<<"file (maze.text) can not open\n";
    }
}

mazeFactory::~mazeFactory() {
	// TODO Auto-generated destructor stub
}

