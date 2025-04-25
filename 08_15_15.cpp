#include<iostream>

using namespace std;
void welcome()
{
	cout << "              Welcome To" << endl;
	cout << "             RAT IN A MAZE" << endl;
	cout << "           @HanYu Zhai, 2025" << endl;
}
void inputMaze()
{

}
bool findPath()
{
	path = new arrayStack<position>;
	position offset[4];
	offset[0].row = 0; offset[0].col = 1;
	offset[1].row = 1; offset[1].col = 0;
	offset[2].row = 0; offset[2].col = -1;
	offset[3].row = -1; offset[3].col = 0;
	for (int i = 0; i <= size + 1; i++)
	{
		maze[0][i] = maze[size + 1][i] = 1;
		maze[i][0] = maze[i][size + 1] = 1;
	}
	position here;
	here.row = 1;
	here.col = 1;
	maze[1][1] = 1;
	int option = 0;
	int lastOption = 3;
	while (here.row != size || here.col != size)
	{
		int r, c;
		while (option <= lastOption)
		{
			r = here.row + offset[option].row;
			c = here.col + offset[option].col;
			if (maze[r][c] == 0)break;
			option++;
		}
		if (option <= lastOption)
		{
			path->push(here);
			here.row = r;
			here.col = c;
			maze[r][c] = 1;
			option = 0;
		}
		else
		{
			if (path->empty())
				return false;
			position next = path->top();
			path->pop();
			if (next.row == here.row)
				option = 2 + next.col - here.col;
			else option = 3 + next.row - here.row;
			here = next;
		}
	}
	return true;
}
void outputPath()
{

}
void rat_maze()
{
	welcome();
	inputMaze();
	if (findPath())
		outputPath();
	else
		cout << "No path " << endl;
}
int main()
{
	rat_maze();
	return 0;
}