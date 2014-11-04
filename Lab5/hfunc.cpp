#include <stdio.h>
#include "taskf.h"

// ============================================
// This is cpp file where all the necesary misc
// functionality will be included

void readInt(char* message, int &n){
	// Recieves message, prints it and read integer
	// into n variable
	printf(message);
	scanf_s("%d", &n);
}


void selectTask(int taskNum){
	switch (taskNum){
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 4: task4(); break;
		case 5: task5(); break;
		case 6: task6(); break;
		case 7: task7(); break;
		case 8: task2(); break;
		case 9: task2(); break;
		case 10: task2(); break;
		default: printf("No such task ... yet.");
	}
}