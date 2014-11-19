#include <stdio.h>
#include <math.h>
using namespace std;

// ============================================
// This is cpp file where all the necesary misc
// functionality will be included

void readInt(char* message, int &n){
	// Recieves message, prints it and read integer
	// into n variable
	printf(message);
	scanf_s("%d", &n);
}

/* Vector class*/
class Vect{
	int x, y;
public:
	Vect(int x, int y);
	Vect(Vect *clone);
	void rotate(double degree);
	Vect operator * (const int);
	int X();
	int Y();
};


Vect::Vect(int x, int y){
	this->x = x;
	this->y = y;
}

Vect::Vect(Vect *clone){
	this->y = clone->y;
	this->x = clone->x;
}

int Vect::X(){ return x; }
int Vect::Y(){ return y; }

void Vect::rotate(double degree){
	int xn = x*cos(degree) - y*sin(degree);
	int yn = x*sin(degree) + y*cos(degree);
	x = xn;
	y = yn;
}

Vect Vect::operator* (const int multiplicand){
	x = x*multiplicand;
	y = y*multiplicand;
}