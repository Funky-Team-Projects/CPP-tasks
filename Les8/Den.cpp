#include<iostream>

using namespace std;


class DenMaze {
	bool *maze;


public:
	DenMaze(int a, int b);
	~DenMaze();
	void creation();
};

DenMaze::DenMaze(int a, int b){
	maze = new bool[a,b];
}

DenMaze::~DenMaze(){
}

void DenMaze::creation(){

}