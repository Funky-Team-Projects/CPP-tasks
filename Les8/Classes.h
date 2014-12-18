//=====================
//include guard defined
#ifndef __Classes_H__
#define __Classes_H__
//=====================
//included dependencies
#include<list>
#include"hfunc.h"
using namespace std;
//=====================
//included classes
class MazeGenerator {
private:
	list <Point> toProcess;
	bool** isProcessed;
	int** maze;
	int mazeRows, mazeCols;
	int rows, cols;

	void generatePaths();
	void initMaze();
public:
	MazeGenerator(int rows, int columns);
	int** getMaze();
	int getWidth();
	int getHeight();
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

#endif