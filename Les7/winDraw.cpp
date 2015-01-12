#include <iostream>
#include <Windows.h>
using namespace std;

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

WinDraw::WinDraw(){
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

WinDraw::~WinDraw(){
	ReleaseDC(myconsole, mydc);
	cin.ignore();
}

void WinDraw::putRect(double x1, double y1, double x2, double y2){
	for (int y = y1; y < y2; y++)
	{
		for (int x = x1; x < x2; x++)
		{
			putPixel(x, y);
		}
	}

}

void WinDraw::drawLine(double x0, double y0, double x1, double y1){
	double x = x0; double y = y0;
	for (double t = 0; t < 1; t+=0.01)
	{
		SetPixel(mydc, x, y, color);
		x = x0 + (x1 - x0)*t;
		y = y0 + (y1 - y0)*t;
	}
}

void WinDraw::setConsoleSize(int width, int height){
	/* ==== Exception should be added*/
	RECT rectCur;
	GetWindowRect(myconsole, &rectCur); //stores the console's current dimensions

	SMALL_RECT rectNew;
	rectNew.Top = 0;
	rectNew.Left = 0;
	rectNew.Bottom = height-1;
	rectNew.Right = width-1;

	COORD coord;
	coord.X = width;
	coord.Y = height;

	SetConsoleScreenBufferSize(consoleHandle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(consoleHandle, TRUE, &rectNew);         // Set Window Size 

	MoveWindow(myconsole, rectCur.left, rectCur.top, width, height, TRUE);
}

void WinDraw::setConsolePos(int x, int y){
	RECT r;
	GetWindowRect(myconsole, &r); //stores the console's current dimensions
	MoveWindow(myconsole, x, y, r.right, r.bottom, TRUE);
}

void WinDraw::setColor(COLORREF color){
	this->color = color;
}

void WinDraw::clearScreen(){
	system("cls");
}

void WinDraw::pause(){
	cin.get();
}

void WinDraw::putPixel(double x, double y){
	SetPixel(mydc, x, y, color);
}

void WinDraw::sleep(int milliseconds){
	Sleep(milliseconds);
}

