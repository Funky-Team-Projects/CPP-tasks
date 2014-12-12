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
class Point{
public:
	double x, y;
	Point(int x, int y);
};

//included functionality
void readInt(char* message, int &n);


#endif