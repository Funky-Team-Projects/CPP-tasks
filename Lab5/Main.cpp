#include "taskf.h"
#include <iostream>

using namespace std;

int main(){
	char a;
	do {
		system("cls");
		int taskNumber;
		readInt("Enter task number: ", taskNumber);
		selectTask(taskNumber);
		cout << "Want to do anything else ?  y/n	"; cin >> a;
	} while (a != 'n');
	return 0;
}