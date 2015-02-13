#include <iostream>
#include <Windows.h>
using namespace std;

class StdDraw {
	HWND myconsole;
	HDC mydc;
	HANDLE consoleHandle;
	COLORREF color;

	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPSTR lpCmdLine;
	int nCmdShow;

public:
	StdDraw(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow);
	~StdDraw();
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

StdDraw::StdDraw(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow){

	HWND hwnd;
	MSG msg;
	WNDCLASS w;
	memset(&w, 0, sizeof(WNDCLASS));
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc;
	w.hInstance = hInstance;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.lpszClassName = L"My Class";
	RegisterClass(&w);
	hwnd = CreateWindow(L"My Class", L"My title", WS_OVERLAPPEDWINDOW,
		300, 200, 200, 180, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
}

StdDraw::~StdDraw(){
	ReleaseDC(myconsole, mydc);
	cin.ignore();
}

void StdDraw::putRect(double x1, double y1, double x2, double y2){
	for (int y = y1; y < y2; y++)
	{
		for (int x = x1; x < x2; x++)
		{
			putPixel(x, y);
		}
	}

}

void StdDraw::drawLine(double x0, double y0, double x1, double y1){
	double x = x0; double y = y0;
	for (double t = 0; t < 1; t += 0.01)
	{
		SetPixel(mydc, x, y, color);
		x = x0 + (x1 - x0)*t;
		y = y0 + (y1 - y0)*t;
	}
}

void StdDraw::setConsoleSize(int width, int height){
	/* ==== Exception should be added*/
	RECT rectCur;
	GetWindowRect(myconsole, &rectCur); //stores the console's current dimensions

	SMALL_RECT rectNew;
	rectNew.Top = 0;
	rectNew.Left = 0;
	rectNew.Bottom = height - 1;
	rectNew.Right = width - 1;

	COORD coord;
	coord.X = width;
	coord.Y = height;

	SetConsoleScreenBufferSize(consoleHandle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(consoleHandle, TRUE, &rectNew);         // Set Window Size 

	MoveWindow(myconsole, rectCur.left, rectCur.top, width, height, TRUE);
}

void StdDraw::setConsolePos(int x, int y){
	RECT r;
	GetWindowRect(myconsole, &r); //stores the console's current dimensions
	MoveWindow(myconsole, x, y, r.right, r.bottom, TRUE);
}

void StdDraw::setColor(COLORREF color){
	this->color = color;
}

void StdDraw::clearScreen(){
	system("cls");
}

void StdDraw::pause(){
	cin.get();
}

void StdDraw::putPixel(double x, double y){
	SetPixel(mydc, x, y, color);
}

void StdDraw::sleep(int milliseconds){
	Sleep(milliseconds);
}

