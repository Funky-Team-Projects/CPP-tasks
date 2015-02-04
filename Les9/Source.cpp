#include<iostream>
#include<stdio.h>
#include<conio.h>
#include"WinDraw.h"

using namespace std;

int main(){
	WinDraw* wd = new WinDraw();
	int x1 = 10, y1 = 10;
	int x2 = 100, y2 = 100;
	wd->setColor(RGB(255, 0, 0));
	wd->putRect(x1, y1, x1 + 10, y1 + 10);
	wd->setColor(RGB(0, 0, 255));
	wd->putRect(x2, y2, x2 + 10, y2 + 10);
	char key = 0;
	while (true){


		if (_kbhit()){
			key = _getch();
			// First rect
			wd->setColor(RGB(0, 0, 0));
			wd->putRect(x1, y1, x1+10, y1+10);
			if (key == 'w') y1 -= 10;
			if (key == 's') y1 += 10;
			if (key == 'd') x1 += 10;
			if (key == 'a') x1-= 10;
			wd->setColor(RGB(255, 0, 0));
			wd->putRect(x1, y1, x1 + 10, y1 + 10);

			// Second rect
			wd->setColor(RGB(0, 0, 0));
			wd->putRect(x2, y2, x2 + 10, y2 + 10);
			if (key == '[') y2 -= 10;
			if (key == '\'') y2 += 10;
			if (key == '\\') x2 += 10;
			if (key == ';') x2 -= 10;
			wd->setColor(RGB(0, 0, 255));
			wd->putRect(x2, y2, x2 + 10, y2 + 10);

		}


		
	}
	return 0;

}