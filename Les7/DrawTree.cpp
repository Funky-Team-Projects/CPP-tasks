#include "hfunc.h"

namespace tree{
	WinDraw * wd;
	const double EPSILON = 4;
	const int C_WIDTH = 600, C_HEIGHT = 600;
	const double B_SIZE = 140;
	const double MULTIPLIER = 0.6;
	const double angle2 = M_PI / 3;
	const double angle1 = M_PI / 3;
	const bool thirdBranchOn = false;
}

using namespace tree;

void Dtree(double x, double y, Vect* v, int depth){
	if (v->lengthSqr() < EPSILON) return;
	wd->setColor(RGB(depth*5, 255-depth*18, 166-depth*25));
	wd->drawLine(x, y, x + v->X(), y + v->Y());
	
	Vect *v1 = new Vect(v);
	Vect *v2 = new Vect(v);
	Vect *v3 = new Vect(v);

	v1->multiply(MULTIPLIER);
	v2->multiply(MULTIPLIER);
	v3->multiply(MULTIPLIER);
	v1->rotate(angle1); 
	v2->rotate(-angle2);

	Dtree(x + v->X(), y + v->Y(), v1, depth+1);
	Dtree(x + v->X(), y + v->Y(), v2, depth+1);
	if (thirdBranchOn) Dtree(x + v->X(), y + v->Y(), v3, depth + 1);
	delete v;

}

void DrawTree(){
	wd = new WinDraw();
	wd->setConsoleSize(C_WIDTH, C_HEIGHT);
	wd->setColor(RGB(255, 255, 255));
	//wd->drawLine(5, 5, 100, 100);

	Dtree(C_WIDTH/2, (C_HEIGHT/3)+300, new Vect(0, -B_SIZE), 0);
	delete wd;
	wd->pause();
}