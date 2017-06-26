#include<iostream>
#include"MazeTool.h"
#include"DataStructure.h"
#include"A_star.h"
#include"DrawMaze.h"
using namespace std;

MAZE maze = {0};


int main()
{
	MazeTool mazetool;
	mazetool.CreateMaze(maze,29,29);
	
    PosType start(27,1);
    PosType end(1,27);
	A_star Astar;
	Astar.MazePath(maze, start, end);
	//mazetool.MazePath(maze,start,end);
	mazetool.OutputMaze(maze, 29,29);
	DrawMaze mazepath;
	mazepath.capturure(maze, 29, 29, start, end);
	cvWaitKey(0);
	system("pause");
    return 0;
}
