#include<list>
#include"hfunc.h"
using namespace std;

class MazeGenerator {
private:
	list<Point> toProcess;
	bool** isProcessed;
	int** maze;
	int mazeRows, mazeCols;
	int rows, cols;

	void generatePaths();
	void initMaze();
public:
	MazeGenerator(int rows, int columns);
	int** getMaze();
	int getWidth();
	int getHeight();
};

void MazeGenerator::initMaze(){
	// Allocating memory
	maze = new int*[mazeCols];
	isProcessed = new bool*[mazeCols];
	for (int i = 0; i < mazeRows; i++)
	{
		maze[i] = new int[mazeRows];
		isProcessed[i] = new bool[mazeRows];
	}
	// Filling array with zeors or ones
	for (int x = 0; x < mazeCols; x++)
		for (int y = 0; y < mazeRows; y++){
			if ((y % 2 == 0) && (x % 2 == 0)) maze[x][y] = 1;
			else maze[x][y] = 0;
		}
	//Filling border elements with zeros
		for (int x = 0; x < mazeCols; x++)
		{
			maze[x][0] = 0;
			maze[x][mazeRows - 1] = 0;
			isProcessed[x][0] = true;
			isProcessed[x][mazeRows - 1] = true;
		}
		for (int y = 0; y < mazeRows; y++)
		{
			maze[0][y] = 0;
			maze[mazeCols-1][y] = 0;
			isProcessed[0][y] = true;
			isProcessed[mazeCols-1][y] = true;
		}
}

void MazeGenerator::generatePaths(){
	int x = 0; int y = 0;
}

MazeGenerator::MazeGenerator(int rows, int columns){
	this->rows = rows;
	this->cols = columns;
	this->mazeRows = rows * 2 + 3;
	this->mazeCols = cols * 2 + 3;
	initMaze();
}

int MazeGenerator::getHeight(){
	return mazeRows;
}
int MazeGenerator::getWidth(){
	return mazeCols;
}

int** MazeGenerator::getMaze(){
	return maze;
}