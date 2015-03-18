#include <iostream>
#include <fstream>
#include <string>



using namespace std;

int main(){
	fstream inputFileStream;
	inputFileStream.open("test.txt", ios::trunc|ios::out);

	/*
	for (int i = 0; i < 50; i++)
	{
		inputFileStream << "record" << i << endl;
	}
	
	string a, b;
	getline(inputFileStream, a);
	inputFileStream.seekg(0);

	inputFileStream >> b;

	cout << a << endl;
	cout << b << endl;

	inputFileStream.close();
	*/



	inputFileStream.close();

	return 0;
}