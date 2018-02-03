// Lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	int s, h, n, i, g, a;
	s = 0;
	g = 0;

	cout << "Введите размер массива" << endl;
	cin >> n;

	double n1 = n;
	h = ceil(n1/2);

	int *mas = new int [n];

	srand (time(NULL));

	for (i = 0; i < n; i ++) 
		mas[i] = rand()%100 - 50;
	
	a = mas[0];
	for (i = 1; i < n; i++) 
		if (abs(a) > abs(mas[i]))
			a = mas[i];

	cout << "\nМинимальный по модулю элемент массива = " << a << endl;


	cout << "\nВ первой половине массива элементы на четных позициях, во второй на нечетных.\n" << endl;

	for (i = 1; i < n; i = i + 2 )
		cout << i + 1 << ". " << mas[i] << endl;

	for (i = 0; i < n; i = i + 2 )
		cout << i + 1 << ". " << mas[i] << endl;

	for (i = 0; i < n; i++) {
		if (mas[i] < 0)
			s += -mas[i];
		else
			s += mas[i];
	}


	cout << "\nСумма модулей элементов массива = " << s << endl;

	delete [] mas;

	system ("pause");
	return 0;
}

