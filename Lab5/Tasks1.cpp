#include <iostream>
#include <time.h>

using namespace std;

int task2()
{
	int v1,v2,answ,res,mark;
	srand(time(NULL));
	for (int i = 1; i <= 10; i++){
		v1 = rand() % 100 + 1;
		v2 = rand() % 100 + 1;
		if (v1>=v2)
		cout << v1 << " - " << v2 << endl;
		cin >> answ;
		res = v1 - v2;
		if (answ == res) 
			mark++;
	}
	system("pause");
	return 0;
}
int task3()
{
	return 0;
}