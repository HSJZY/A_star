#ifndef DRAWMAZE
#define DRAWMAZE
#include<iostream>
#include <cv.h>
#include <highgui.h>
#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>
#include<math.h>
#include"MazeTool.h"
using namespace std;
using namespace cv;
class DrawMaze
{
public:
	DrawMaze(MAZE maze,int height,int width, PosType start, PosType end);
	DrawMaze();
	IplImage* capturure(MAZE maze, int height, int width, PosType start, PosType end);
	~DrawMaze();

private:

};

DrawMaze::DrawMaze()
{
}
IplImage* DrawMaze::capturure(MAZE maze, int height, int width, PosType start, PosType end)
{
	IplImage* img = cvCreateImage(CvSize(height * 20, width * 20), IPL_DEPTH_8U, 3);
	cvRectangle(img, Point(0, 0), Point(20 * height, 20 * width), Scalar(255, 255, 255), -1, 8);
	cvLine(img, Point(0, 20 * (height - 1)), Point(20 * (width - 1), 20 * (height - 1)), CvScalar(128, 139, 134), 2);
	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 1; j < width - 1; j++)
		{
			//if(i==0)
			if (maze[i][j] == 1)
			{
				cvRectangle(img, Point(20 * j, 20 * i), Point(20 * (j + 1), 20 * (i + 1)), Scalar(0, 0, 0), -1, 8);
			}
			else if (maze[i][j] == 0)
			{

				cvRectangle(img, Point(20 * j, 20 * i), Point(20 * (j + 1), 20 * (i + 1)), Scalar(255, 255, 255), -1, 8);
				cvLine(img, Point(20 * j, 20 * i), Point(20 * j, 20 * (i + 1)), CvScalar(128, 139, 134), 1);
				cvLine(img, Point(20 * j, 20 * i), Point(20 * (j + 1), 20 * i), CvScalar(128, 139, 134), 1);
				cvLine(img, Point(20 * (j + 1), 20 * i), Point(20 * (j + 1), 20 * (i + 1)), CvScalar(128, 139, 134), 1);

			}
			else if (maze[i][j] == 2)
			{
				cvRectangle(img, Point(20 * j, 20 * i), Point(20 * (j + 1), 20 * (i + 1)), Scalar(238, 192, 127), -1, 8);
				//cvRectangle(img, Point(20 * j, 20 * i), Point(20 * (j + 1), 20 * (i + 1)), Scalar(0, 0, 255), -1, 8);
			}
			else if (maze[i][j] == 3)
			{
				cvRectangle(img, Point(20 * j, 20 * i), Point(20 * (j + 1), 20 * (i + 1)), Scalar(80, 228, 255), -1, 8);//FFE4C4
			}

		}
	}
	cvRectangle(img, Point(20 * start.getY(), 20 * start.getX()), Point(20 * (start.getY() + 1), 20 * (start.getX() + 1)), Scalar(0, 255, 137), -1, 8);
	cvRectangle(img, Point(20 * end.getY(), 20 * end.getX()), Point(20 * (end.getY() + 1), 20 * (end.getX() + 1)), Scalar(0, 0, 255), -1, 8);
	//cvRectangle(img, Point(20 * (end.getY()-2), 20 * (end.getX()+1)), Point(20 * (end.getY()-1), 20 * (end.getX()+2)), Scalar(0, 0, 255), -1, 8);
	namedWindow("canvas", CV_WINDOW_AUTOSIZE);
	cvShowImage("canvas", img);
	//imshow("canvas", img);
	waitKey(100);
	return img;
}

DrawMaze::DrawMaze(MAZE maze,int height,int width,PosType start,PosType end)
{
	
}

DrawMaze::~DrawMaze()
{
}
#endif // !DRAWMAZE
