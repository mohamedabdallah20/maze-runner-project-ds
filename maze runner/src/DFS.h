#include <string>
using namespace std;


class node
{
public:
	int x,y;
	node *next;
	node();
	~node();
};

class DFS {
 public:
	int width=7,height=5;
	string  maze[12]=
	{
		{"+-+-+-+-+-+-+-+"},
		{"|*|   | | |   |"},
		{"+ +-+ + + +-+ +"},
		{"|   |   |     |"},
		{"+ + + +-+ +-+ +"},
		{"| |   |     | |"},
		{"+ +-+-+ +-+-+ +"},
		{"|       |     |"},
		{"+-+ + +-+-+ +-+"},
		{"|   |        0|"},
		{"+-+-+-+-+-+-+-+"},
	};
	DFS();
    ~DFS();
};
