// Выведение y=b+kx.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	float x1, x2, y1, y2, b, k;

	cout<< "Введите X1 = ";
	cin>> x1;
	cout<< "Введите Y1 = ";
	cin>> y1;
	cout<< "Введите X2 = ";
	cin>> x2;
	cout<< "Введите Y2 = ";
	cin>> y2;

	k=(y1-y2)/(x1-x2);
	b=(y2*x1 - y1*x2)/(x1-x2);

	cout<< "y = " << b << " + " << k << "x" << endl;

	system ("pause");

	return 0;
}

