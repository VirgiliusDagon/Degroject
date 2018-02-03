// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	int n, i, j;
	double min, product, sum, b;

	sum = 0;
	product = 1;

	cout << "Введите размер массива" << endl;
	cin >> n;

	double *mas = new double [n];

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		mas[i] = (rand()%100 - 50)/3.62;
		if (mas[i] > 0)
			product *= mas[i];
	}

	min = mas[i];
	for (i = 1; i < n; i++) 
		if (min > mas[i])
			min = mas[i];
	for (i = 0; i < n; i++) {
		if (mas[i] == min)
			break;
		sum += mas[i];
	}

	cout << "Минимальный элемент массива  = " << min << endl;
	cout << "Сумма элементов до минимального = " << sum << endl;
	cout << "Произведение положительных элементов = " << product << endl << endl;
	
	for (j = 0; j < n; j++)
		for(i = 0; i < n - 1; i++)
			if(mas[i] > mas[i + 1]) {
				b = mas[i];
				mas[i] = mas[i+1];
				mas[i+1]=b;
			}

	for (i = 0; i < n; i += 2)
		cout << i + 1 << ". " << setw(10) << setprecision(6) << mas[i] << endl;
	cout << endl;
	for (i = 1; i < n; i += 2)
		cout<< i + 1 << ". " << setw(10) << setprecision(6) << mas [i] << endl;

	delete [] mas;
	system ("pause");
	return 0;
}

