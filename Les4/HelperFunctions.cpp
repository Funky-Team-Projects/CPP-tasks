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

int mostProblemSolver(int a, int b, bool(*f)(int)) {
	int res = 0;
	for (int i = a; i <= b; i++){
		bool check = (*f)(i);
		if (check) res += i;	
	}
	return res;
}