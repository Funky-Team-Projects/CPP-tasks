#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "hfunc.h"

using namespace std;

//=======================================
// This cpp file contains implementations
// of tasks form 6 to 10

int task6(){
	return 0;
}

int task7(){
	return 0;
}

int task8(){
	return 0;
}

int task9(){
	return 0;
}

int task10(){
	//In PROGRESS...........
	int N,z=0;
	cout << "Enter N> "; cin >> N;
	for (int i = 1; i <= N; i++){
		if (happyNum(i) == true){
			cout << setw(6) << i << endl;
			z++;
		}
		
	}
	cout << z << " Happy numbers" << endl;
	return 0;
}