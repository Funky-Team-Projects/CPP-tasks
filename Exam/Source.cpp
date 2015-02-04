#include <stdio.h>
#include<limits.h>

using namespace std;

int rows, cols;

//=================
// Helper functions
void readInt(char* message, int &n){
	// Recieves message, prints it and read integer
	// into n variable
	printf(message);
	scanf_s("%d", &n);
}

int** readArray(){
	//Initializing variables
	int tmp;
	readInt("Enter number of rows:", rows);
	readInt("Enter number of cols:", cols);
	//Allocating array memory
	int** a = new int*[cols];
	for (int x = 0; x < cols; x++) a[x] = new int[rows];

	//Enter array data
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			printf("row: %d, col: %d - ", y, x);
			scanf_s("%d", &a[x][y]);
		}
		printf("End of row! \n");
	}
	return a;
}

void showArray(int **a){
	printf("\n Array data: \n");
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			printf("- %d -", a[x][y]);
		}
		printf("\n");
	}
}

//========================
// Task functions

int findMinInCol(int **a, int col){
	int min = INT_MAX;
	for (int y = 0; y < rows; y++)
	{
		if (a[col][y] < min) min = a[col][y];
	}
	return min;
}

int findMaxInRow(int **a, int row){
	int max = INT_MIN;
	for (int x = 0; x < cols; x++)
	{
		if (a[x][row] > max) max = a[x][row];
	}
	return max;
}


void showSpecial(int** a){
	//Initializing tag arrays
	int* minInCol = new int[rows];
	int* maxInRow = new int[cols];
	//Showing and fillin tag arrays
	printf("\n");
	for (int x = 0; x < cols; x++){
		minInCol[x] = findMinInCol(a, x);
		printf(" Minindex in col %d: %d \n", x, minInCol[x]);
	}
	printf("\n");
	for (int y = 0; y < rows; y++){
		
		maxInRow[y] = findMaxInRow(a, y);
		printf(" Maxindex in row %d: %d \n", y, maxInRow[y]);
	}
	//Showing special elements
	printf("\n");
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if ((a[x][y] == maxInRow[y]) && (a[x][y] == minInCol[x])) printf("Special element: row - %d, col - %d \n", y, x);
		}
	}

}



int main(){
	int** data = readArray();
	showArray(data);
	showSpecial(data);

	//system("PAUSE");
	return 0;
}