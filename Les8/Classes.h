//=====================
//include guard defined
#ifndef __Classes_H__
#define __Classes_H__
//=====================
//included dependencies
#include<list>
#include"hfunc.h"
using namespace std;
//=====================
//included classes
class MazeGenerator {
private:
	list <Point> toProcess;
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

#endif