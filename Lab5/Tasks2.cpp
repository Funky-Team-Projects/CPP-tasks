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
	int N, K, b, z = 1, K0 = 0, l = 0;
	int arrayNum[100];
	//cout << "Enter N> "; cin >> N;
	readInt("Enter N> ", N);
	readInt("Enter K> ", K);
	//cout << "Enter K> "; cin >> K;
	for (int i = 2; i <= N; i++){
		z = 0;
		b = i;
		
		//////////////////////////////////////////////
		

		while (b!=0){
			arrayNum[z] = b % 2;
			if (b % 2 != 0){
				K0++;
				l++;
			}
			else l++;
			z++;
			b = b / 2;
		}
		if (b == 1)
			arrayNum[l + 1] = 1;
		for (int I = l; I >= 0; I--){
			cout << arrayNum[I];
			
		}
		cout << endl;
		/////////////////////////////////////////////////
		/*if (K0 == K) {
			for (int I = l; I > 0; I--)
				cout << arrayNum[I];
			cout << endl;
		}*/
	}
	//cout << "Number with 0 in them = " << z << endl;
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