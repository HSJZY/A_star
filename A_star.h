#include<vector>
#include<iostream>
#include"DataStructure.h"
#include"MazeTool.h"
#include"DrawMaze.h"
using namespace std;
class A_star
{
public:
	A_star();
	A_star(MAZE maze, PosType start,PosType end);
	~A_star();
	int calc_H(PosType current, PosType end);
	int calc_F(int H, int G);
	void MazePath(MAZE maze, PosType start, PosType end);

private:

};

A_star::A_star()
{
}
A_star::A_star(MAZE maze, PosType start, PosType end)
{
	MazePath(maze,start, end);
}
A_star::~A_star()
{
}
//ŒÆËãHÖµ
int A_star::calc_H(PosType current, PosType end)
{
	return abs(end.getX() - current.getX()) + abs(end.getY()-current.getY());
}
//ŒÆËãGÖµ
int A_star::calc_F(int H,int G) 
{
	return H + G;
}
//Ö÷º¯Êý
void A_star::MazePath(MAZE maze, PosType start, PosType end)
{
	vector<PosType> vecPath;
	int G = 0;
	bool getPath=false;
	start.setG(G);
	start.setF(calc_F(calc_H(start, end), G));
	start.changeParent(start);
	PosType curPos = start;
    OpenList Open(curPos);
	ClosedList Closed;
	//ÖÆ×÷ÊÓÆµ
	CvVideoWriter *writer = 0;//ÓÃÓÚÊÓÆµÐŽÈë
	int isColor = 1;
	int fps = 20; // or 25
	int frameW = 580; // 744 for firewire cameras
	int frameH = 580; // 480 for firewire cameras
	writer = cvCreateVideoWriter("out.avi", CV_FOURCC('X', 'V', 'I', 'D'), fps, cvSize(frameW, frameH), isColor);
	DrawMaze expansion;
	while (!Open.isEmpty())
	{
		PosType currentMin = Open.getFirst();
		
		
		//cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE);
		IplImage* img = expansion.capturure(maze,29,29,start,end);
		//cvShowImage("mainWin", img);
		cvWriteFrame(writer, img);
		//maze[currentMin.getX()][currentMin.getY()] = 3;
		if (currentMin.getX() == end.getX() && currentMin.getY() == end.getY())//ÕÒµœÂ·Ÿ¶
		{
			getPath = true;
			//maze[currentMin.getX()][currentMin.getY()] = 2;
			int *parent= currentMin.getParent();
			while (currentMin.getX()!=start.getX()||currentMin.getY()!=start.getY())
			{
				vecPath.push_back(currentMin);
				//maze[currentMin.getX()][currentMin.getY()] = 2;
				cout << "("<< currentMin.getX()<<","<< currentMin.getY()<<")"<<endl;
				currentMin = Closed.getback(*parent, *(parent + 1));
				parent = currentMin.getParent();
				//maze[*parent][*(parent + 1)] = 2;
			}
			cout << "(" << currentMin.getX() << "," << currentMin.getY() << ")" << endl;
			vecPath.push_back(currentMin);
			
			while (vecPath.size()!=0)
			{
				int i = vecPath.size()-1;
				PosType curpos = vecPath[i];
				vecPath.pop_back();
				maze[curpos.getX()][curpos.getY()] = 2;
				//DrawMaze(maze, 29, 29, start, end);
				//DrawMaze forVideo;
				IplImage* img= expansion.capturure(maze, 29, 29, start, end);
				//cvShowImage("mainWin", img);
				cvWriteFrame(writer, img);
				//cvWaitKey(5);
			}
			//cvWaitKey(100);
			cvReleaseVideoWriter(&writer);
			cvDestroyWindow("mainWin");
			//maze[*parent][*(parent + 1)] = 2;
			break;
		}
		Closed.appendElement(currentMin);
		maze[currentMin.getX()][currentMin.getY()] = 3;
		Open.deleteElement(currentMin);
		int k = 0;
		while (k < 4)
		{
			int X = currentMin.getX() + direction[k][0];
			int Y = currentMin.getY() + direction[k][1];
			k++;
            PosType surround(X,Y);
			if (maze[X][Y] == 1)
			{
				Closed.appendElement(surround);//°ÑÇœÌíŒÓµœ±ÕŒ¯Àï±ß
				continue;
			}
			if (Closed.elemInList(surround))
			{
				continue;
			}
			else
			{
				int newG = currentMin.getG() + 1;
				int newH = calc_H(surround, end);
				int newF = newG + newH;
				if (Open.elemInList(surround))
				{
					if (newG < surround.getG())
					{
						surround.setG(newG);
						surround.setF(newF);
						surround.changeParent(currentMin);
						//Open.insertElement(surround);
					}
					else
					{
						continue;
					}
				}
				else
				{
					surround.setG(newG);
					surround.setF(newF);
					surround.changeParent(currentMin);
					//maze[surround.getX()][surround.getY()] = 3;
					Open.insertElement(surround);
				}
			}
		}
	}
	if (getPath == false)
	{
		cout << "no path in map from("<<start.getX()<<","<<start.getY()<<")to("<<end.getX()<<","<<end.getY()<<")"<<endl;
	}
}
