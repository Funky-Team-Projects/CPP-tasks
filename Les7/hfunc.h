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
	void putPixel(double x, double y);
};

/* Vector class*/
class Vect{
	double x, y;
public:
	Vect(double x, double y);
	Vect(Vect *clone);
	void rotate(double degree);
	double lengthSqr();
	double length();
	void multiply(double multiplicand);
	double X();
	double Y();
};

//included functionality
# define M_PI 3.14159265358979323846  /* pi */

void readInt(char* message, int &n);


#endif