#include <iostream>
#include "hfunc.h"

using namespace std;

void main(){
	winDraw * wd = new winDraw();
	wd->setConsolePos(100, 100);
	wd->setConsoleSize(800, 600);
	wd->setColor(RGB(255, 255, 255));
	wd->drawLine(5, 5, 100, 100);
	delete wd;
}