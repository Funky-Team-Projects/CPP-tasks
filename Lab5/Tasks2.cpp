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
	int N, K, b, z = 0, K0, maxSim;
	int arrayNum[100];
	readInt("Enter N> ", N);
	readInt("Enter K> ", K);
	for (int i = 1; i <= N; i++)
		z=z+binaryCode(i,K);
	cout << "\n\n\nNumber with 0 in them = " << z<< endl;
	return 0;
}

int task9(){
	return 0;
}

int task10(){
	int N,z=0;
	cout << "Enter N> "; cin >> N;
	for (int i = 1; i <= N; i++){
		if (happyNum(i) == true){
			cout << setw(6) << i << endl;
			z++;
		}
		
	}
	cout << endl << z << " Happy numbers" << endl;
	return 0;
}