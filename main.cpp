#include "funcs.h"

int main()
{
	srand(time(NULL));
	int rows = 4, cols = 4;
	int** array = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		*(array + i) = new int[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			array[i][j] = rand() % 10;
		}
	}
	printFunc(array, rows, cols);
	moveRows(array, rows, cols, 2, 'd');
	cout << endl;
	printFunc(array, rows, cols);
	moveCols(array, rows, cols, 3, 'r');
	cout << endl;
	printFunc(array, rows, cols);
	for (int i = 0; i < rows; i++) {
		delete[] array[i];
	}
	delete[] array;

	return 0;
}