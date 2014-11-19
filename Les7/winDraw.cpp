#include <iostream>
#include <Windows.h>
using namespace std;

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

winDraw::winDraw(){
	//Get a console handle
	myconsole = GetConsoleWindow();
	//Get a handle to device context
	mydc = GetDC(myconsole);
	//==================================
	// Adding some style
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, false }; // Visibility
	SetConsoleCursorInfo(consoleHandle, &cursor);
}

winDraw::~winDraw(){
	ReleaseDC(myconsole, mydc);
	cin.ignore();
}

void winDraw::drawLine(double x0, double y0, double x1, double y1){
	int x = x0; int y = x0;
	for (double t = 0; t < 1; t+=0.002)
	{
		SetPixel(mydc, x, y, color);
		x = x0 + (x1 - x0)*t;
		y = y0 + (y1 - y0)*t;
	}
}

void winDraw::setConsoleSize(int width, int height){
	/* ==== Exception should be added*/
	RECT r;
	GetWindowRect(myconsole, &r); //stores the console's current dimensions
	MoveWindow(myconsole, r.left, r.top, width, height, TRUE);
}

void winDraw::setConsolePos(int x, int y){
	RECT r;
	GetWindowRect(myconsole, &r); //stores the console's current dimensions
	MoveWindow(myconsole, x, y, r.right, r.bottom, TRUE);
}

void winDraw::setColor(COLORREF color){
	this->color = color;
}

void winDraw::clearScreen(){
	system("cls");
}

void winDraw::pause(){
	cin.get();
}

void winDraw::putPixel(int x, int y){
	SetPixel(mydc, x, y, color);
}

void winDraw::sleep(int milliseconds){
	Sleep(milliseconds);
}

