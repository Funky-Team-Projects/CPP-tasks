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
	void putPixel(int x, int y);
};
/* Vector class*/
class Vect{
	int x, y;
public:
	Vect(int x, int y);
	Vect(Vect *clone);
	void rotate(double degree);
	Vect operator * (const int);
	int X();
	int Y();
};

//included functionality
void readInt(char* message, int &n);


#endif