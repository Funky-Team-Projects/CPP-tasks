#include<vector>
#include"hfunc.h"
using namespace std;

class MazeGenerator {
private:
	vector<Tuple> toProcess;
	bool** isProcessed;
	int** maze;
	int mazeRows, mazeCols;
	int rows, cols;

	void generatePaths();
	void initMaze();
	void addAdjToWall(Point* block);
public:
	MazeGenerator(int rows, int columns);
	int** getMaze();
	int getWidth();
	int getHeight();
};

void MazeGenerator::initMaze(){
	//Added
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
	int x = 2; int y = 2;
	//Adding inicial walls
	maze[x][y] = true;
	Tuple *t1 = new Tuple(new Point(x + 1, y), new Point(x + 2, y));
	Tuple *t2 = new Tuple(new Point(x, y + 1), new Point(x, y + 2));
	toProcess.push_back(*t1);
	toProcess.push_back(*t2);
	while (!toProcess.empty()){
		//Chosing random tuple
		int n = rand() % toProcess.size();
		Tuple t = toProcess.at(rand() % toProcess.size());
		toProcess.erase(toProcess.begin()+n);
		Point *too = t.too;
		Point *wall = t.wall;
		//Adding element to maze spanning tree
		isProcessed[wall->x][wall->y] = true;
		maze[wall->x][wall->y] = 1;
		//Adding adjusted walls
		addAdjToWall(too);
	}


}

void MazeGenerator::addAdjToWall(Point* block){
	int x = block->x;
	int y = block->y;
	if (!isProcessed[x][y + 2]){
		Tuple* t1 = new Tuple(new Point(x, y + 1), new Point(x, y + 2));
		toProcess.push_back(*t1);
	}
	if (!isProcessed[x][y - 2]){
		Tuple* t2 = new Tuple(new Point(x, y - 1), new Point(x, y - 2));
		toProcess.push_back(*t2);
	}
	if (!isProcessed[x + 2][y]){
		Tuple* t3 = new Tuple(new Point(x + 1, y), new Point(x + 2, y));
		toProcess.push_back(*t3);
	}
	if (!isProcessed[x - 2][y]){
		Tuple* t4 = new Tuple(new Point(x - 1, y + 1), new Point(x - 2, y));
		toProcess.push_back(*t4);
	}
}

MazeGenerator::MazeGenerator(int rows, int columns){
	this->rows = rows;
	this->cols = columns;
	this->mazeRows = rows * 2 + 3;
	this->mazeCols = cols * 2 + 3;
	initMaze();
	generatePaths();
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