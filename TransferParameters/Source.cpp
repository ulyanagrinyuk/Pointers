#include<iostream>
using namespace std;

#define delimitr "\n------------------------------------\n"


void Exchange(int a, int b);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	cout << a << "\t" << b << endl;
	cout << &a << "\t" << &a << endl;
	cout << delimitr << endl;
	Exchange(a, b);
	cout << delimitr << endl;
	cout << a << "\t" << b << endl;
	cout << &a << "\t" << &b << endl;

}

void Exchange(int a, int b)
{
	cout << &a << "\t" << &b << endl;
	int buffer = a;
	a = b;
	b = buffer;
	cout << a << "\t" << b << endl;
}