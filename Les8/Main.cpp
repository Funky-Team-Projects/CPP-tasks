#include <iostream>
#include "classes.h"
#include <vector>

using namespace std;

int main(){
	MazeGenerator * mg = new MazeGenerator(25, 25);
	mg->generatePaths();
	return 0;
	/*
			#include <stdio.h>
			#include <conio.h>

			using namespace std;
			void main(){
			while (true){
			if (_kbhit()){
			printf("HIT!\n");
			_getch();
		}

	}

}
	*/
}