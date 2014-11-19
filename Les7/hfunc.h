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
class winDraw {
	HWND myconsole;
	HDC mydc;
	HANDLE consoleHandle;
	COLORREF color;
public:
	winDraw();
	~winDraw();
	void setColor(COLORREF color);
	void drawLine(double x1, double y1, double x2, double y2);
	void setConsoleSize(int width, int height);
	void setConsolePos(int x, int y);
	void clearScreen();
	void pause();
	void sleep(int milliseconds);
	void putPixel(int x, int y);
};

//included functionality
void readInt(char* message, int &n);


#endif