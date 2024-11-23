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
void deleteFunc(T** &array, int& rows, int cols, int pos)
{
	T** new_a = new T * [rows - 1];
	for (int i = 0; i < pos; i++)
	{
		*(new_a + i) = *(array + i);
	}
	delete[] array[pos];
	for (int i = pos + 1; i < rows; i++)
	{
		*(new_a + i - 1) = *(array + i);
	}
	delete[] array;
	array = new_a;
	rows--;
}