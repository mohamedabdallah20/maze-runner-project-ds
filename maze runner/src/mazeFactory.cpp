
#include "mazeFactory.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

node::node(){
	x=0;
	y=0;
	up=0;
	down=0;
	right=0;
	left=0;
}
node::~node(){

}



mazeFactory::mazeFactory() {
width=0;
height=0;
    maze.open("maze.text");
    if(maze.is_open()){

    	maze>>width>>height;

    	y=width*2+2;x=height*2+2;

    	mazeS=new char*[x-1];
    	for(int i=0;i<x-1;i++){
    		mazeS[i]=new char[y];
    	}
    	for(int i=0;i<x-1;i++){
    		for(int j=0;j<y;j++)
    		{
    			maze.get(mazeS[i][j]);
    	    }

    	}
       maze.close();
    }

    else{
    	cout<<"file (maze.text) can not open\n";
    }

    visited=new bool*[x-1];
        for(int i=0;i<x-1;i++)
        {
        	visited[i]=new bool[y];
        }

        for(int i=0;i<x-1;i++)
         {
         	for(int j=0;j<y;j++)
         	{
         		visited[i][j]=0;
         	}
         }


    intmaze=new int*[x-1];
    for(int i=0;i<x-1;i++)
    {
    	intmaze[i]=new int[y];
    }

   for(int i=0;i<x-1;i++)
    {
    	for(int j=0;j<y;j++)
    	{
    		if(mazeS[i][j]=='*')
    		{
    		intmaze[i][j]=5;
    		node *n=new node;
    		n->x=i;
    		n->y=j;
    		root=n;
    		}
    		else if(mazeS[i][j]=='0')
    			intmaze[i][j]=8;
    		else if(mazeS[i][j]==' ')
    			intmaze[i][j]=1;
    		else if(mazeS[i][j]=='-'||mazeS[i][j]=='\n'||mazeS[i][j]=='+'||mazeS[i][j]=='|')
    			intmaze[i][j]=0;
    	}
    }
    cout<<root->x<<" "<<root->y<<endl;
    cout<<mazeS[1][2]<<endl;
    for(int i=0;i<x-1;i++)
        {
        	for(int j=0;j<y;j++)
        	{
        		cout<<intmaze[i][j];
        	}
        	cout<<endl;

        }


}


void mazeFactory::graph(node *cell,bool bup,bool bdown,bool bright,bool bleft){

	cout<<'('<<cell->x<<" , "<<cell->y<<')'<<endl;
	if (intmaze[cell->x-1][cell->y]==1&&bup==true&&visited[cell->x-2][cell->y]==false)
		{
		   node *n=new node;
		   n->x=cell->x-2;
		   n->y=cell->y;
		   cell->up=n;
		   visited[cell->x-2][cell->y]=true;
		   mazeS[n->x][n->y]='.';
		   cout<<"up\n";
		   graph(n,true,false,true,true);
		}
	if (intmaze[cell->x][cell->y+1]==1&&bright==true&&visited[cell->x][cell->y+2]==false)
		{
	       node *n=new node;
	       n->x=cell->x;
	       n->y=cell->y+2;
	       cell->right=n;
	       visited[cell->x][cell->y+2]=true;
	       mazeS[n->x][n->y]='.';
	       cout<<"right\n";
	       graph(n,true,true,true,false);
		}
	if (intmaze[cell->x+1][cell->y]==1&&bdown==true&&visited[cell->x+2][cell->y]==false)
		{
	       node *n=new node;
	       n->x=cell->x+2;
	       n->y=cell->y;
	       cell->down=n;
	       visited[cell->x+2][cell->y]=false;
	       mazeS[n->x][n->y]='.';
	       cout<<"down\n";
	       graph(n,false,true,true,true);
		}
	 if (intmaze[cell->x][cell->y-1]==1&&bleft==true&&visited[cell->x][cell->y-2]==false)
		{
	       node *n=new node;
	       n->x=cell->x;
	       n->y=cell->y-2;
	       cell->left=n;
	       visited[cell->x][cell->y-2]=false;
	         mazeS[n->x][n->y]='.';
	       cout<<"left\n";
	       graph(n,true,true,false,true);
		}

}

void mazeFactory::getgraph(){
	graph(root,1,1,1,1);
	//
	coutgraph(root);
	for(int i=0;i<x-1;i++){
			for(int j=0;j<y;j++)
			{
				cout<<mazeS[i][j];
			}
	    }
}

void mazeFactory::coutgraph(node*start){

	cout<<'('<<start->x<<" , "<<start->y<<')'<<endl;
	if(start->up!=0){
	coutgraph(start->up);
	}
	if(start->down!=0){
	coutgraph(start->down);

	}
	if(start->right!=0){

	coutgraph(start->right);
	}
	if(start->left!=0){
	coutgraph(start->left);

	}


}

mazeFactory::~mazeFactory() {

}

