#include<iostream>
#include "tfunc.h"

using namespace std;


void task1(){
	int n = 0;
	while (n <= 0) {
		readInt("Please insert natural number > ", n);
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
	int n = 0;
	while (n <= 0) {
		readInt("Please insert natural number > ", n);
	}
	bool truth[3];
	int i = 0, digit, first;

	while (n != 0) {
		i++;
		digit = n % 10;
		if (i == 1) {
			truth[1] = digit <= 6;
			first = digit;
		}
		n = n / 10;
	} 
	truth[0] = i == 4;
	truth[2] = digit == first;

	cout << "Number is four-digited - " << (truth[0] ? "true" : "false") << endl;
	cout << "First digit is not more than 6 - " << (truth[1] ? "true" : "false") << endl;
	cout << "First digit equals the last one - " << (truth[2] ? "true" : "false") << endl;
	if (digit < first) cout << "Last digit is bigger than first";
	else if (digit > first) cout << "First digit is bigger than last";
	else if (digit = first) cout << "First and last digits are equal";
	cout << "\n";
}

void task5(){

}

void task7(){

}