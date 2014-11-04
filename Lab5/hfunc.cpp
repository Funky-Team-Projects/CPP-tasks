#include <stdio.h>

void readInt(char* message, int &n){
	printf(message);
	scanf_s("%d", &n);
}