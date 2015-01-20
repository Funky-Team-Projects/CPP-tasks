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

/* WinDraw class */
class WinDraw {
	HWND myconsole;
	HDC mydc;
	HANDLE consoleHandle;
	COLORREF color;
public:
	WinDraw();
	~WinDraw();
	void setColor(COLORREF color);
	void drawLine(double x1, double y1, double x2, double y2);
	void setConsoleSize(int width, int height);
	void setConsolePos(int x, int y);
	void clearScreen();
	void pause();
	void sleep(int milliseconds);
	void putPixel(double x, double y);
	void putRect(double x1, double y1, double x2, double y2);
};


//included functionality
void readInt(char* message, int &n);


#endif