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
void addRows(T**& array, int& rows, int cols, T* array_1, int pos)
{
	T** new_a = new T * [rows + 1];
	for (int i = 0; i < pos; i++)
	{
		*(new_a + i) = *(array + i);
	}
	new_a[pos] = new T[cols];
	for (int i = 0; i < cols; i++)
	{
		*(*(new_a + pos) + i) = *(array_1 + i);
	}
	for (int i = pos; i < rows; i++)
	{
		*(new_a + i + 1) = *(array + i);
	}
	delete[] array;
	array = new_a;
	rows++;
}

template <typename T>
void deleteRows(T**& array, int& rows, int cols, int pos)
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

template <typename T>
void addCols(T**& array, int rows, int& cols, T* array_1, int pos)
{
	T** new_a = new T * [rows];
	for (int i = 0; i < rows; i++) {
		new_a[i] = new T[cols + 1];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < pos; j++) {
			*(*(new_a + i) + j) = *(*(array + i) + j);
		}
		*(*(new_a + i) + pos) = *(array_1 + i);
		for (int j = pos; j < cols; j++) {
			*(*(new_a + i) + j + 1) = *(*(array + i) + j);
		}
	}
	for (int i = 0; i < rows; i++) {
		delete[] array[i];
	}
	delete[] array;
	array = new_a;
	cols++;
}

template <typename T>
void deleteCols(T**& array, int rows, int& cols, int pos)
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


template <typename T>
void moveCols(T**& array, int rows, int cols, int qty, char direction)
{
	qty %= cols;
	if (qty == 0) return;
	switch (direction) {
	case 'l':
		for (int i = 0; i < qty; i++) {
			for (int j = 0; j < rows; j++) {
				T temp = array[j][0];
				for (int k = 0; k < cols - 1; k++) {
					array[j][k] = array[j][k + 1];
				}
				array[j][cols - 1] = temp;
			}
		}
		break;

	case 'r':
		for (int i = 0; i < qty; i++) {
			for (int j = 0; j < rows; j++) {
				T temp = array[j][cols - 1];
				for (int k = cols - 1; k > 0; k--) {
					array[j][k] = array[j][k - 1];
				}
				array[j][0] = temp;
			}
		}
		break;
	}
}

template <typename T>
void moveRows(T**& array, int rows, int cols, int qty, char direction)
{
	qty %= rows;
	if (qty == 0) return;
	switch (direction) {
	case 'u':
		for (int i = 0; i < qty; i++) {
			T* temp = array[0];
			for (int j = 0; j < rows - 1; j++) {
				array[j] = array[j + 1];
			}
			array[rows - 1] = temp;
		}
		break;

	case 'd':
		for (int i = 0; i < qty; i++) {
			T* temp = array[rows - 1];
			for (int j = rows - 1; j > 0; j--) {
				array[j] = array[j - 1];
			}
			array[0] = temp;
		}
		break;
	}
}