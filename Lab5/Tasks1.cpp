#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "hfunc.h"

using namespace std;

//=======================================
// This cpp file contains implementations
// of tasks form 1 to 5

int task1(){
	int v1 = 1, v2 = 2, answ, res, mark = 0;
	srand(time(NULL));

	////////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 1; i <= 10; i++){
		v1 = rand() % 10 + 1;
		v2 = rand() % 10 + 1;
		cout << i << ". " << v1 << " * " << v2 << " = "; cin >> answ;
		res = v1 * v2;
		if (answ == res)
			mark++;
	} // вывод примеров и запись результата

	//////////////////////////////////////////////////////////////////////////////////////////////

	if (mark == 10) cout << "Your mark is " << setw(3) << mark << " =>  EXELENT" << endl;
	else if (mark > 7) cout << "Your mark is " << setw(3) << mark << " =>  GOOD ENOUGH" << endl;
	else if (mark > 5) cout << "Your mark is " << setw(3) << mark << " =>  AVERAGE" << endl;
	else cout << "Your mark is " << setw(3) << mark << " =>  YOU SUCK" << endl; //подсчет полученых баллов и вывод оценки
	system("pause");
	return 0;
}
int task2()
{
	int v1 = 1, v2 = 2, answ, res, mark = 0;
	srand(time(NULL));

	////////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 1; i <= 10; i++){
		while (v1 < v2) {
			v1 = rand() % 100 + 1;
			v2 = rand() % 100 + 1;
		} //цикл генерации случайных чисел с условием что первое больше или равно второму
		cout << i << ". " << v1 << " - " << v2 << " = "; cin >> answ;
		res = v1 - v2;
		if (answ == res)
			mark++;
		v1 = 1;
		v2 = 2;
	} // вывод примеров и запись результата

	//////////////////////////////////////////////////////////////////////////////////////////////

	if (mark == 10) cout << "Your mark is " << setw(3) << mark << " =>  EXELENT" << endl;
	else if (mark > 7) cout << "Your mark is " << setw(3) << mark << " =>  GOOD ENOUGH" << endl;
	else if (mark > 5) cout << "Your mark is " << setw(3) << mark << " =>  AVERAGE" << endl;
	else cout << "Your mark is "<< setw(3) << mark << " =>  YOU SUCK" << endl; //подсчет полученых баллов и вывод оценки
	system("pause");
	return 0;
}

int task3(){
	float vklad = 1000,inc;
	for (int i = 3; i <= 12; i++){
		vklad *= 1.02;
		cout << "Vklad na " << i << " mesjac = " << vklad<<endl;
	}
	vklad = 1000;
	for (int i = 1; i <= 10; i++){
		inc = vklad*0.02;
		vklad = vklad + inc;
		cout << "Prirost za " << i << " mesjac " << inc << endl;
	}
	return 0;
}

int task4(){
	//* Edited by Vladislav...
	double distanceInitial = 10;
	double distanceSum = 0, distanceCurrent = distanceInitial;
	int days;
	readInt("Enter number of days in run: ", days);
	for (int i = 1; i < days; i++)
	{
		distanceCurrent = distanceCurrent*1.1;
		distanceSum += distanceCurrent;
		printf("Day - %f ; Distance: %f", i, distanceCurrent);
	}
	printf("Summar distance in %d days is %d", distanceSum, distanceSum);
	return 0;
}
int task5(){
	
	return 0;
}
