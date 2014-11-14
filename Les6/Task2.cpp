#include<iostream>

using namespace std;

void readInt(char* message, int &n){
	// Recieves message, prints it and read integer
	// into n variable
	printf(message);
	scanf_s("%d", &n);
}

void task2(){
	printf("This program finds first 15 numbers that divides by 19 \n");
	int n = 100;
	//Find fitst number after 100 that dividesby 19;
	while (n % 19) n++;
	printf("%d \n", n);
	for (int i = 0; i < 14; i++)
	{
		n += 19;
		printf("%d \n", n);
	}
}

void task4(){

}

void task6(){

}

void task8(){

}