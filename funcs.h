#include "libs.h" 

#include "libs.h" 

template <typename T>
void printFunc(T** array, int rows, int cols)
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
void deleteFunc(T**& array, int rows, int& cols, int pos)
{
	T** new_a = new T * [rows];
	for (int i = 0; i < rows; i++) {
		new_a[i] = new T[cols - 1];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < pos; j++) {
			*(*(new_a + i) + j) = *(*(array + i) + j);
		}
		for (int j = pos + 1; j < cols; j++) {
			*(*(new_a + i) + j - 1) = *(*(array + i) + j);
		}
	}
	for (int i = 0; i < rows; i++) {
		delete[] array[i];
	}
	delete[] array;
	array = new_a;
	cols--;
}
	