#include<vector>
#include"hfunc.h"
#include<time.h>
using namespace std;

class MazeGenerator {
private:
	vector<Tuple*> toProcess;
	bool** isProcessed;
	int** maze;
	int mazeRows, mazeCols;
	int rows, cols;

	void show();
	void generatePaths();
	void initMaze();
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
			isProcessed[x][y] = false;
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
	//Initializing first stuff;
	isProcessed[2][2] = true;
	Tuple* t1 = new Tuple(new Point(3, 2), new Point(4, 2));
	Tuple* t2 = new Tuple(new Point(2, 3), new Point(2, 4));
	
	toProcess.push_back(t1);
	toProcess.push_back(t2);

	while (!toProcess.empty()){
		//Taking tuple
		int n = rand() % toProcess.size();
		Tuple * tupleToProcess = toProcess[n];
		toProcess.erase(toProcess.begin()+n);
		//Processing it

		//Open chosen block
		int x = tupleToProcess->Too()->x; int y = tupleToProcess->Too()->y;
		if (!isProcessed[x][y]) maze[tupleToProcess->Wall()->x][tupleToProcess->Wall()->y] = 1;
		isProcessed[x][y] = true;

		/*show();
		system("PAUSE");*/

		//Add adj walls;
		if (!isProcessed[x][y + 2]) toProcess.push_back((new Tuple(new Point(x, y + 1), new Point(x, y + 2))));
		if (!isProcessed[x][y - 2]) toProcess.push_back((new Tuple(new Point(x, y - 1), new Point(x, y - 2))));
		if (!isProcessed[x + 2][y]) toProcess.push_back((new Tuple(new Point(x + 1, y), new Point(x + 2, y))));
		if (!isProcessed[x - 2][y]) toProcess.push_back((new Tuple(new Point(x - 1, y), new Point(x - 2, y))));

	}
}

void MazeGenerator::show(){
	for (int y = 0; y < mazeRows; y++)
	{
		for (int x = 0; x < mazeCols; x++)
		{
			if (maze[x][y] == 1) printf("O");
			else printf(" ");

		}
		printf("\n");
	}
}

MazeGenerator::MazeGenerator(int rows, int columns){
	this->rows = rows;
	this->cols = columns;
	this->mazeRows = rows * 2 + 3;
	this->mazeCols = cols * 2 + 3;
	srand(time(NULL));
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