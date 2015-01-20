#include <iostream>
#include "classes.h"
#include <vector>

using namespace std;

int main(){
	MazeGenerator * mg = new MazeGenerator(25, 25);
	mg->generatePaths();
	return 0;
}