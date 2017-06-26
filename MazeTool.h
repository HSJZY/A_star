#ifndef MAZETOOL
#define MAZETOOL
#include<iostream>
#include<set>
#include<vector>
#include<list>
#include<math.h>
#include"DataStructure.h"
typedef int MAZE[29][29];
int direction[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
using namespace std;
class MazeTool
{
public:
	MazeTool();
	~MazeTool();
	void OutputMaze(MAZE maze, int width, int height);
	void CreateMaze(MAZE maze,int width,int height);

private:

};

MazeTool::MazeTool()
{
}

MazeTool::~MazeTool()
{
}
void MazeTool::CreateMaze(MAZE maze, int width, int height)
{
	
	int mywall[200][2] = { {1,11},{2,11},{3,11},{4,11},{5,11},{6,11},{7,11},{8,11},{9,11},{10,11},{10,12},{10,13},{10,14},{10,15},{10,16},{10,17},{10,18},{10,19},{ 9,15 },{ 9,16 },{ 9,17 },{ 9,18 },{ 9,19 },{ 8,15 },{ 8,16 },{ 8,17 },{ 8,18 },{ 8,19 },{ 11,15 },{ 11,16 },{ 11,17 },{ 11,18 },{ 11,19 },
	{3,20},{3,21},{3,22},{3,23},{ 4,20 },{ 4,21 },{ 4,22 },{ 4,23 },{5,20 },{ 5,21 },{ 5,22 },{ 5,23 } ,
	{7,24},{8,24},{9,24},{10,24},{11,24},{12,24},
	{13,5},{13,6},{13,7},{13,8},{13,9},{13,10},{13,11},{14,11},{15,11},{16,11},{17,11},{18,11},{19,8},{19,9},{19,10},{19,11},{19,12},{19,13},{19,14},{ 20,8 },{ 20,9 },{ 20,10 },{ 20,11 },{ 20,12 },{ 20,13 },{ 20,14 },{ 21,8 },{ 21,9 },{ 21,10 },{ 21,11 },{ 21,12 },{ 21,13 },{ 21,14 } ,
	{14,13},{14,14},{14,15},{14,16},{14,17},{14,18},{ 14,19 },{ 14,20 },{ 14,21 },{ 14,22 },{ 14,23 },{ 14,24 },{ 14,25 },{ 14,26 },{ 14,27 },
	{24,1},{24,2},{24,3},{24,4},{24,5},{24,6},{24,7},{24,8},
	{23,13},{23,14},{23,15},{23,16},{23,16},{ 24,13 },{ 24,14 },{ 24,15 },{ 24,16 },{ 24,16 },{ 25,13 },{ 25,14 },{ 25,15 },{ 25,16 },{ 25,16 },{ 26,13 },{ 26,14 },{ 26,15 },{ 26,16 },{ 26,16 },{ 27,13 },{ 27,14 },{ 27,15 },{ 27,16 },{ 27,16 } };
	list<int> wallList(200,2);
	for (int i = 0; mywall[i][0]>0; i++)
	{
		int x = mywall[i][0], y = mywall[i][1];
		maze[x][y] = 1;
		//wallList.insert(mywall[i][0],mywall[i][1]);
	}
	for (int i = 0; i < width; i++)
	{
		maze[0][i] = 1;
		maze[i][0] = 1;
		maze[28][i] = 1;
		maze[i][28] = 1;
	}
	
}
void MazeTool::OutputMaze(MAZE maze,int width,int height)
{
	int i, j;
	for (i = 0; i < height; i++)
	{
		for ( j = 0; j < width; j++)
		{
			//x = i*width + j;

			cout << maze[i][j]<<' ';
		}
		cout << endl;
	}
}
#endif // !MAZETOOL
