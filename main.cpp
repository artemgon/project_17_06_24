#include "funcs.h"

int main()
{
	int rows = 3, cols = 4, index = 1;
	int** array = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			*(*(array + i) + j) = i * cols + j;
		}
	}
	printFunc(array, rows, cols);
	cout << endl;
	deleteFunc(array, rows, cols, index);
	printFunc(array, rows, cols);
	for (int i = 0; i < rows; ++i) {
		delete[] array[i];
	}
	delete[] array;
	return 0;
}