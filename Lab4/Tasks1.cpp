#include "taskf.h"
#include "hfunct.h"


using namespace std;

// WE VERY ENJOY ALL YOU ARE DOING
// PLEASE CONTINUE THIS WORK
//      ||  ||
//      ||  ||
//  \\         //
//   \\       //
//    ((=====))


int 2(){
	return task2();
}

int task2(){
	return task3();
}

int task3(){
	cout << "BOOM HAPPENED!!!";
	return 0;
}

int task4(){
	return 0;
}

int task5(){
	return 0;
}

int task6(){
	return 0;
}

int task7(){
	task9();

	return 0;
}

int task8(){
	return 0;
}

int task9(){
	int a, b;
	int res = 0;
	readInt("Please, would you be so kindly to insert the first number>", a);
	readInt("Please, would you be so kindly to insert the first number>", b);
	res = mostProblemSolver(a, b, [](int i){return i*i % 10 == 6; });
	cout << "Drumroll .... Sum is equal " << res << endl;
	
	return 0;
}

int task10(){
	return 0;
}
