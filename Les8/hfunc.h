//=====================
//include guard defined
#ifndef __hfunc_H__
#define __hfunc_H__
//=====================
//included dependencies
#include <iostream>
#include <Windows.h>
#include<time.h>

//=====================
//included classes
class Point{
public:
	int x, y;
	Point(int x, int y);
};

class Tuple{
public:
	Tuple(Point* wall, Point*too);
	Point* Too();
	Point* Wall();
};

//included functionality
void readInt(char* message, int &n);


#endif