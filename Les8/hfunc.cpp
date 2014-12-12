#include <stdio.h>
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

class Point{
public:
	double x, y;
	Point(int x, int y);
};

Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}