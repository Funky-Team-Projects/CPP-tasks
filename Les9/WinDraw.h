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
	WinDraw(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow);
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


#endif