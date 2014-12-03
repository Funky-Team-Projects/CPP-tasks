#include "hfunc.h"
#include <time.h>


namespace koh{
	WinDraw * wd;
	const double sigma = 0.5;
	const double sizeOfBow = 450;
	const double initX = 100;
	const double initY = 130;

	int iteration = 55;
}

using namespace koh;

void drawBow(double x, double y, Vect* v, int depth){
	if (v->lengthSqr() < sigma){
		wd->drawLine(x, y, x + v->X(), y + v->Y());
		iteration++;
		wd->setColor(RGB(iteration / 35, 255 - iteration/40, iteration / 23));
		return;
	}

	Vect * v1 = new Vect(v);
	Vect * v2 = new Vect(v);
	Vect * v3 = new Vect(v);
	v1->multiply(1.0 / 3.0);
	v3->multiply(1.0 / 3.0);
	v2->multiply(1.0 / 3.0);
	v2->rotate(-M_PI / 3);
	v3->rotate(+M_PI / 3);

	drawBow(x, y, v1, depth+1);
	drawBow(x + v1->X(), y + v1->Y(), v2, depth + 1);
	drawBow(x + v1->X() + v2->X(), y + v1->Y() + v2->Y(), v3, depth + 1);
	drawBow(x + v1->X() + v2->X() + v3->X(), y + v1->Y() + v3->Y() + v2->Y(), v1, depth + 1);

	
}

void DrawStar(){
	srand(time(NULL));
	wd = new WinDraw();
	wd->setConsoleSize(800, 600);
	wd->setColor(RGB(0, 255, 255));
	Vect * v1 = new Vect(sizeOfBow, 0);
	Vect * v2 = new Vect(v1);
	Vect * v3 = new Vect(v1);


	drawBow(initX, initY, v1, 0);

	double x2 = initX + v1->X();
	double y2 = initY + v1->Y();
	v2->rotate(M_PI * 2.0 / 3.0);
	drawBow(x2, y2, v2, 0);

	double x3 = x2 + v2->X();
	double y3 = y2 + v2->Y();

	v2->rotate(M_PI * 2.0 / 3.0);
	drawBow(x3, y3, v2, 0);

	delete v1;
	delete v2;
	delete v3;
	delete wd;
}