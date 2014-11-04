#include <iostream>

using namespace std;

void task1()
{
	int a, b, sum = 0, z = 0;
	float sredArif;
	cout << "Enter A> "; cin >> a;
	cout << "Enter B> "; cin >> b;
	for (int i = a; i <= b; i++)
	if (i % 10 == 7)
	{
		sum = sum + i;
		z++;
	}
	if (z != 0)
		sredArif = sum / z;
	cout << "Average of " << a << " and " << b << " that end with 7 are " << sredArif << endl;
	system("pause");
}