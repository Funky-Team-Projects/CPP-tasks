#include<iostream>
#include "tfunc.h"

using namespace std;


void task1(){
	int n = 0;
	while (n <= 0) {
		cout << "Please insert natural number > ";
		cin >> n;
	}

	char min = 10, max = -1;
	char digit;
	do {
		digit = n % 10;
		if (max < digit) max = digit;
		if (min > digit) min = digit;
		n = n / 10;
	} while (n != 0);

	cout << "Max digit is " << (int)max << endl;
	cout << "Min digit is " << (int)min << endl;


}

void task3(){

}

void task5(){

}

void task7(){

}