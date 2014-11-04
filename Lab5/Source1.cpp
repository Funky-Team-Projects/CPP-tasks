#include <iostream>

using namespace std;

void exc13()
{
	int a, b, sum = 0, z = 0;
	float sredArif;
	for (int i = a; i <= b; i++)
	if (i % 10 == 7)
	{
		sum = sum + i;
		z++;
	}
	if (z != 0)
		sredArif = sum / z;
	cout << "Average of " << a << " and " << b << " are " << sredArif << endl;
	system("pause");
}