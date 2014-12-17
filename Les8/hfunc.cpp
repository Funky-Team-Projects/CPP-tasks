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
	int x, y;
	Point(int x, int y);
};

Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}

class Tuple{
	Point *too;
	Point *wall;
public:
	Tuple(Point* wall, Point*too);
	Point* Too();
	Point* Wall();
};

Tuple::Tuple(Point* wall, Point*too){
	this->too = new Point(too->x, too->y);
	this->wall = new Point(wall->x, wall->y);
}

Point* Tuple::Too(){ return too; }
Point* Tuple::Wall(){ return wall; }