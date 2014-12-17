//=====================
//include guard defined
#ifndef __hfunc_H__
#define __hfunc_H__
//=====================
//included dependencies
#include <iostream>
#include <Windows.h>

//=====================
//included classes
//added coment
class Point{
public:
	int x, y;
	Point(int x, int y);
};

class Tuple{
public:
	Point *wall;
	Point *too;
	Tuple(Point* wall, Point* too);
};
//included functionality
void readInt(char* message, int &n);


#endif