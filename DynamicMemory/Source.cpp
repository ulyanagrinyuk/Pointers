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

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T* arr, int& n, T value);
template<typename T>T* push_front(T* arr, int& n, T value);
template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);

template<typename T>T* insert(T* arr, int& n, T value, int index);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index);
template<typename T>void insert_col(T** arr,int& col, const int rows, const int index);

template<typename T>T* pop_back(T* arr, int& n);
template<typename T>T* pop_front(T* arr, int& n);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);

template<typename T> void push_col_back(T** arr, const int rows, int& cols);
template<typename T>T** push_col_front(T* arr, int& col, const int rows);
template<typename T>T** push_cols_back(T** arr, int& cols, const int rows);
template<typename T>void pop_col_front(T** arr, int& cols, const int rows);
template<typename T>void pop_col_back(T** arr, int& cols, const int rows);

template<typename T>T** erase(T* arr, int& n, int index);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, const int index);
template<typename T>void erase_cols(T** arr, int& cols, const int rows);


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

	cout << "Добавляем пустую строку в конец массива:" << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "Добавляем пустую строку в начало массива:" << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	/*cout << "Добавляем пустой столбик в конец  массива:" << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;*/


	/*cout << delimiter << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);*/

	/*FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, rows);*/

	/*int rows, cols;
	cout << "Введите кол-во строк:"; cin >> rows;
	cout << "Введите кол-во столбцов:"; cin >> cols;
	int** arr = Allocate<int>(rows, cols);
	clock_t _start = clock();
	arr = PushRowBack(arr, rows, cols);
	cout << "Строка добавлена:" << double(t_end - t_start);*/

	int index;
	cout << "Введите индекс добовляемой строки:"; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows,cols);

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
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
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

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	//return Print(arr, new T[n]);
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T* push_back(T* arr, int& n, T value)
{
	//1
	T* buffer = new T[n + 1];
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
template<typename T>T* push_front(T* arr, int& n, T value)
{
	return push_back(arr, n, new T[value]);
}

template<typename T>T* insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
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

template<typename T>T* pop_back(T* arr, int& n)
{
	return pop_back(arr, n);
}
template<typename T>T* pop_front(T* arr, int& n)
{
	return pop_front(arr, n);
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	
	return push_back(arr, rows, new T[cols]{}); 
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{	
	return push_back(arr, rows, new T[cols]{});
}

template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	return insert(arr, rows, new T[cols]{}, index);
	
}
template<typename T>void insert_col(T** arr, int& col, const int rows, const int index)
{
	return insert_col(arr, col, rows, index);
}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	return push_back(arr, rows, new T[cols]);
}

template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	return pop_front(arr, rows, new T[cols]);
}

template<typename T>void pop_col_front(T** arr, int& cols, const int rows)
{
	return pop_front(arr, cols, new T[rows]);
}
template<typename T>void pop_col_back(T** arr, int& cols, const int rows)
{
	return pop_back(arr, cols, new T[rows]);
}

template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	return push_back(arr, new T[rows], cols);
}

template<typename T>T** push_col_front(T* arr, int& col, const int n)
{
	return push_front(arr, col, new T[n]);
}

template<typename T>T** push_cols_back(T** arr, int& cols, const int rows)
{
	return push_back(arr, cols, new T[rows]);
}
template<typename T>T** erase(T* arr, int& n, int index)
{
	return erase(arr, n, new T [index]);
}

template<typename T>T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	return erase_row(arr, rows, new T[cols][index]);
}

template<typename T>void erase_cols(T** arr, int& cols, const int rows)
{
	return erase_cols(arr, cols, new T[rows]);
}



















