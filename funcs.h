#include "libs.h" 

template <typename T>
void printFunc(T ** array, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(array + i) + j) << " ";
		}
		cout << endl;
	}
}

template <typename T>
void addFunc(T** &array, int& rows, int cols, T *array_1)
{
	T** new_a = new T * [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		*(new_a + i) = *(array + i);
	}
	new_a[rows] = new T[cols];
	for (int i = 0; i < cols; i++)
	{
		*(*(new_a + rows) + i) = *(array_1 + i);
	}
	delete[] array;
	array = new_a;
	rows++;
}