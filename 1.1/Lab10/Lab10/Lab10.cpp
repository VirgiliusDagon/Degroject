// Lab10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

template <class T>
T Max (T **, int);
template <class T>
void SredKvad (T **, int);
template <class T>
int Check (T **, int, int);


int _tmain(int argc, _TCHAR* argv[]) {

	setlocale (LC_ALL, "rus");

	int i, j, n, c;

	cout << "Введите размер массива ";
	cin >> n;

	cout << "C = ";
	cin >> c;

	int **masI = new int *[n];
	for (i = 0; i < n; i++)
		masI[i] = new int [n];

	srand (time (NULL));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			masI[i][j] = rand ()% 10 - 5;

	double **masD = new double *[n];
	for (i = 0; i < n; i++)
		masD[i] = new double [n];

	srand (time (NULL));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			masD[i][j] = rand ()% 10 - 4;

	cout << "Кол-во элементов матрицы больше C " << Check (masI, n, c) << endl;

	SredKvad (masI, n);

	cout << "Максимальный элемент массива ниже побочной диагонали " << Max (masI, n) << endl;

	cout << endl << endl;

	cout << "Кол-во элементов матрицы больше C " << Check (masD, n, c) << endl;

	SredKvad (masD, n);

	cout << "Максимальный элемент массива ниже побочной диагонали " << Max (masD, n) << endl;

	for (i = 0; i < n; i++)
		delete [] masI [i];
	delete [] masI;

	for (i = 0; i < n; i++)
		delete [] masD [i];
	delete [] masD;

	system ("pause");
	return 0;
}
template <class T>
T Max (T **mas, int n) {

	int max = mas[1][n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i + j + 1 > n && mas[i][j] > max)
				max = mas[i][j];
	return max;
}
template <class T>
void SredKvad (T **mas, int n) {

	double stroka, stolb;

	for (int i = 0; i < n; i++) {
		stroka = 0;
		stolb = 0;
		for (int j = 0; j < n; j++) {
				stroka += pow (mas[i][j], 2.0);
				stolb += pow (mas[j][i], 2.0);
		}
		cout << "Среднеквадратичное " << i + 1 << " столбца и строки " << sqrt (stroka / n) << " " << sqrt (stolb / n) << endl; 
	}
	return;
}
template <class T>
int Check (T **mas, int n, int c) {

	int counter = 0, i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (mas[i][j] > c)
				counter++;
	return counter;
}