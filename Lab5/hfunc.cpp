#include <stdio.h>
#include "taskf.h"
using namespace std;

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
		case 8: task8(); break;
		case 9: task9(); break;
		case 10: task10(); break;
		default: printf("No such task ... yet.");
	}
}
bool happyNum(int num1)   // For task10
{
	bool check = false;
	int aftComa;
	int num = num1;
	while (num > 0) {
		aftComa = num % 10;
		if ((aftComa == 7) || (aftComa == 4)) check = true;
		else return check = false;
		num = num / 10;
	} 
	return check;
} 
int binaryCode(int num, int kolZero)
{
	int K0 = 0, b = num, maxSim = -1, K = kolZero, z=0;
	int arrayNum[100];
	//////////////////////////////////////////////
	do {
		arrayNum[maxSim + 1] = b % 2;
		if (b % 2 == 0)
			K0++;
		maxSim++;

		b = b / 2;
	} while (b > 1);
	if (b == 1){
		arrayNum[maxSim + 1] = 1;
		maxSim++;
	}
	///////////////////////////////////////// - ÷икл записи двоичного кода в €чейки массива
	if (K0 == K){
		z++;
		for (int I = maxSim; I >= 0; I--){
			cout << arrayNum[I];
		}
		cout << endl;
	}
	///////////////////////////////////////////////// - проверка на кол-во нулей в числе и вывод числа(массива) на экран
	return z;
}