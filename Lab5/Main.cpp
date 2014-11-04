#include "taskf.h"
#include <iostream>

using namespace std;

int main(){
	int taskNum;
	cout << "Enter task number> ";  cin >> taskNum;
	switch (taskNum){
	case 1: task1(); break;
	case 2: task2(); break;
	case 3: task3(); break;
	case 4: task4(); break;
	case 5: task5(); break;
	case 6: task6(); break;
	case 7: task7(); break;
	/*case 8: task2(); break;
	case 9: task2(); break;
	case 10: task2(); break;*/
	default:{ cout << "No such task ... yet." << endl; system("pause"); }
	}
	
	return 0;
}