#include <iostream>
#include "classes.h"
#include <vector>

using namespace std;

void showArray(int** a, int X, int Y){
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (a[x][y] == 1) printf(" ");
			else printf("O");
			
		}
		printf("%\n");
	}
}

int main(){
	MazeGenerator * mg = new MazeGenerator(20, 20);
	int** maze = mg->getMaze();
	showArray(maze, mg->getWidth(), mg->getHeight());


	return 0;
}