#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------\n"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);

int* insert(int* arr, int& n, int value, int index);
int** insert_row(int** arr, int& n, const int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);
int* push_col_front(int* arr, int& col, const int rows);
int** push_cols_back(int** arr, int& cols, const int rows);
void pop_col_front(int** arr, int& cols, const int rows);

int* erase(int* arr, int& n, int index);
int** erase_row(int** arr, int& rows, const int cols);
void erase_cols(int** arr, int& cols, const int rows);


//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2
//#define PREFOMANCE_TEST

void main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1



	int n;
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение:"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение:"; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемое значение:"; cin >> index;
	cout << "Введите добавляемое значение:"; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DINAMIC_MEMORY_1

	int rows, cols;
	cout << "Введите кол-во строк:"; cin >> rows;
	cout << "Введите кол-во элементы строк:"; cin >> cols;

	int** arr = Allocate(rows, cols);
		
	/*int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}*/
#ifdef PREFOMANCE_TEST
	cout << "Память выделена, для добавления строки нажмите любую клавишу" << endl;
	system("PAUSE");
	clock_t c_start = clock();
	arr = push_row_back(arr, rows, cols);
	clock_t c_end = clock();
	cout << "Строка добавлена:" << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
	system("PAUSE");
#endif // PREFOMANCE_TEST

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, rows);

	Clear(arr, rows);
}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

void Clear(int** arr, const int rows)
{
	//1
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2
	delete[] arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int* arr, int& n, int value)
{
	//1
	int* buffer = new int[n + 1];
	//2
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3
	delete[] arr;
	//4
	arr = buffer;
	buffer = nullptr;
	cout << typeid(nullptr).name() << endl;
	//5
	arr[n] = value;
	//6
	n++;
	//7
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1] {};
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_back(int* arr, int& n)
{
	/*int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;*/
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols];
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{	
	int** buffer = new int*[rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}

int** insert_row(int** arr, int& rows, const int index)
{
	int** buffer = new int*[rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	buffer[rows] = new int[index];
	rows++;
	return arr;
	
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	int** buffer = new int*[--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int** pop_row_front(int** arr, int& rows, const int cols)
{
	delete[] arr[0];
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

void pop_col_front(int** arr, int& cols, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

int* push_col_front(int* arr, int& col, const int n)
{
	int* buffer = new int[col + 1];
	for (int i = 0; i < col; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = col;
	col++;
	return buffer;
}

int** push_cols_back(int** arr, int& cols, const int rows)
{
	int** buffer = new int*[--cols];
	for (int i = 0; i < cols; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* erase(int* arr, int& n, int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int** erase_row(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

void erase_cols(int** arr, int& cols, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
	int* buffer = new int[cols - 1];
	for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
	delete arr[i];
	arr[i] = buffer;
	}
	cols--;
}



















