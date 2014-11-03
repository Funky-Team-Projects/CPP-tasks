#include <stdio.h>
#include <list>

using namespace std;

void readInt(char* message, int& n){
	printf(message);
	scanf_s("%d", &n);
}

// This is function returns N'h prime number


int factorial(int a){
	return a > 1 ? a*factorial(a - 1) : 1;
}