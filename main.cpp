#include "funcs.h"

int main()
{
	int rows = 3, cols = 4, index = 2;
	int** array_2 = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		array_2[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			*(*(array_2 + i) + j) = i * cols + j;
		}
	}
	printFunc(array_2, rows, cols);
	cout << endl;
	deleteFunc(array_2, rows, cols, index);
	printFunc(array_2, rows, cols);
	for (int i = 0; i < rows; ++i) {
		delete[] array_2[i];
	}
	delete[] array_2;
	return 0;
}