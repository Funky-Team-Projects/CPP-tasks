#include<vector>
#include"hfunc.h"
#include<time.h>

#define corner = 50;

using namespace std;

class MazeGenerator {
private:
	vector<Tuple*> toProcess;
	WinDraw* wd;
	bool** isProcessed;
	int** maze;
	int mazeRows, mazeCols;
	int rows, cols;
	void initMaze();

public:
	void generatePaths();
	MazeGenerator(int rows, int columns);
	void show();
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

	//Drawing first rect
	wd->setColor(RGB(255, 0, 0));
	wd->putRect(50 + 10 * 2, 50 + 10 * 2, 60 + 10 * 2, 60 + 10 * 2);
	wd->setColor(RGB(255, 255, 255));
	wd->putRect(50 + 10 * 2, 50 + 10 * 2, 60 + 10 * 2, 60 + 10 * 2);

	//Putting first element in the list
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
		int cellX = tupleToProcess->Too()->x; int cellY = tupleToProcess->Too()->y;
		int wallX = tupleToProcess->Wall()->x; int wallY = tupleToProcess->Wall()->y;
		if (!isProcessed[cellX][cellY]){
			//Open chosen block if necessary
			maze[wallX][wallY] = 1;
			//Drawing rectangles
			wd->setColor(RGB(255, 255, 255));
			wd->setColor(RGB(255, 255, 255));
			wd->putRect(50+10*wallX, 50+10*wallY, 60+10*wallX, 60+10*wallY);
			wd->setColor(RGB(0, 0, 255));
			wd->putRect(50 + 10 * cellX, 50 + 10 * cellY, 60 + 10 * cellX, 60 + 10 * cellY);
			wd->sleep(150); //Sleep
			wd->setColor(RGB(255, 255, 255));
			wd->putRect(50 + 10 * cellX, 50 + 10 * cellY, 60 + 10 * cellX, 60 + 10 * cellY);
		}
			
		isProcessed[cellX][cellY] = true;

		//Add adj walls;
		if (!isProcessed[cellX][cellY + 2]) toProcess.push_back((new Tuple(new Point(cellX, cellY + 1), new Point(cellX, cellY + 2))));
		if (!isProcessed[cellX][cellY - 2]) toProcess.push_back((new Tuple(new Point(cellX, cellY - 1), new Point(cellX, cellY - 2))));
		if (!isProcessed[cellX + 2][cellY]) toProcess.push_back((new Tuple(new Point(cellX + 1, cellY), new Point(cellX + 2, cellY))));
		if (!isProcessed[cellX - 2][cellY]) toProcess.push_back((new Tuple(new Point(cellX - 1, cellY), new Point(cellX - 2, cellY))));

	}
	delete wd;
	delete isProcessed;
	toProcess.clear();
}

void MazeGenerator::show(){
	for (int y = 0; y < mazeRows; y++)
	{
		for (int x = 0; x < mazeCols; x++)
		{
			if (maze[x][y] == 1) printf(" ");
			else printf("O");

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
	//Init windraw
	wd = new WinDraw();
	wd->setConsoleSize(650, 700);	
	//Done
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