#include <iostream>

using namespace std;

int task2()
{
	int v1;
	for (int i = 1; i <= 10; i++){
		v1 = rand() % 100 + 1;
		cout << v1;
	}
	system("pause");
	return 0;
}