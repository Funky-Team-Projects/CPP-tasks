#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

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
	
	return 0;
}

int task4(){
	double initalRun = 10;
	return 0;
}
int task5(){
	return 0;
}

int task6(){
	return 0;
}

int task7(){
	return 0;
}