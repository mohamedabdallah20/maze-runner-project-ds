#include "DFS.h"
#include <iostream>
#include <string>
using namespace std;

DFS::DFS() {

	visited = new bool[mf.height * mf.width];
	path.push(1);
	found = false;
	sizeofstack = 0;
}
void DFS::getpath(int start) {
	visited[start] = true;
	for (int i = 1; i <= mf.height * mf.width; ++i) {
		if (mf.matrix[path.top()][i] == -1)
			found = true;
		if (mf.matrix[path.top()][i] != 0 && visited[i] == false
				&& found == false) {
			path.push(i);
			getpath(path.top());
		}

	}
	if (found == false) {
		path.pop();
	}

}
void DFS::displaypath() {
	getpath(1);
	sizeofstack = path.size();
	for (int i = 0; i < sizeofstack; ++i) {
		cout << '(' << mf.node_map[path.top()].first << ','
				<< mf.node_map[path.top()].second << ')' << endl;
		mf.mazeS[mf.node_map[path.top()].first][mf.node_map[path.top()].second] =
				'.';
		path.pop();
	}
	for (int i = 0; i < mf.x; ++i) {
		for (int j = 0; j < mf.y; ++j) {
			cout << mf.mazeS[i][j];
		}
	}

}
DFS::~DFS() {

}
