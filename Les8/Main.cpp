#include <iostream>
#include "classes.h"
#include <vector>

using namespace std;

int main(){
/*	MazeGenerator * mg = new MazeGenerator(20, 20);
	int** maze = mg->getMaze();
	dw->setConsoleSize(1300, 600);*/
	//mg->show();
	WinDraw * dw = new WinDraw();
	dw->setConsoleSize(650, 600);
	dw->setColor(RGB(255, 255, 255));

	int shift = 0;
	for (int y = 50; y < 400; y+=50)
	{
		for (int x = 50; x < 500; x+=100)
		{
			dw->putRect(x+shift, y, x + 50+shift, y + 50);
		}
		shift = ((shift == 0) ? 50 : 0);
	}


	return 0;
}