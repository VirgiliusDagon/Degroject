// Lab6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "time.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	int n, m, i, j, nzero, b, N, sum, max;

	nzero = 0;
	sum = 0;


	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;

	if (n < m)
		N = n;
	else 
		N = m;

	int** mas = new int* [n];
	for (i = 0; i < n; i++)
		mas[i] = new int [m];

	srand (time(NULL));

	for (j = 0; j < n; j++)
		for (i = 0; i < m; i++) {
			mas[j][i] = rand () % 100 - 50;
			if (mas[j][i] != 0)
				nzero++;
		}
			


	
	for (j = 0; j < n; j++) {
		b = mas[j][0];
		for (i = 0; i < m - 1; i++) {
			if (mas[j][i] < mas[j][i + 1])
				max = mas[j][i + 1]; 
			if (i + j + 1 > N)
				sum += mas[j][i];
		}
		cout << "\nНаибольший элемент " << j + 1 << "-го столбца = " << max << endl;
	}

	cout << "\nКол-во ненулевых элементов = " << nzero << endl;
	cout << "\nСумма элементов находящихся ниже побочной оси = " << sum << endl;

	for (i = 0; i < n; i++)	
		delete [] mas [i];

	delete [] mas;

	system ("pause");
	return 0;
}

