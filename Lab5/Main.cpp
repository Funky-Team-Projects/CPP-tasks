#include "taskf.h"
#include <iostream>

using namespace std;

int main(){
	int taskNumber;
	readInt("Enter task number: ", taskNumber);
	selectTask(taskNumber);
	system("pause");
	return 0;
}