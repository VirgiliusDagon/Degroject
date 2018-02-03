// Pract5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	int i, j, zero, max, SumCol, SumLn;

	zero = 0;

	int **mas = new  int *[14];
	for (i = 0; i < 14; i++)
		mas[i] = new int [14];

	int **sums = new int *[2];
	for (i = 0; i < 2; i++)
		sums[i] = new int [14];


	srand(time(NULL));

	cout << "Первое число сумма элементов столбика матрицы, второй сумма элементов строки,\nотсортированных методом выбора" << endl;

	for (i = 0; i < 14; i++) 
		for (j = 0; j < 14; j++) {
			mas[i][j] = rand()%100 - 50;
			if (mas[i][j] == 0)
				zero++;
		}

	for (i = 0; i < 14; i++) {
		sums[0][i] = 0;
		sums[1][i] = 0;
		for (j = 0; j < 14; j++) {
			if (mas[i][j] > 0)
				sums[0][i] += mas[i][j];
			if (mas[j][i] > 0)
				sums[1][i] += mas[j][i];
		}
	}

	max = mas[0][0];
	for (i = 0; i < 14; i++)
		for (j = 0; j < 14; j++)
			if (i + j + 1 >= 14 && max < mas[i][j])
				max = mas [i][j];

	for (i = 0; i < 14; i++) {
		SumCol = sums[0][0];
		SumLn = sums[1][0];
		for (j = i + 1; j < 14; j++) {
			if (sums[0][i] < sums[0][j]) {
				SumCol = sums[0][i];
				sums[0][i] = sums[0][j];
				sums[0][j] = SumCol;
			}
			if (sums[1][i] < sums[1][j]) {
				SumLn = sums[1][i];
				sums[1][i] = sums[1][j];
				sums[1][j] = SumLn;
			}
		}
		cout << setw(4) << sums[0][i] << "  " << sums[1][i] << endl;

	}
	cout << "Максимальный элемент ниже побочной диагонали = " << max << endl;
	cout << "Кол-во нулевых элементов = " << zero << endl;

	for (i = 0; i < 14; i++)
		delete [] mas[i];

	delete [] sums[0];
	delete [] sums[1];
	delete [] sums;
	delete [] mas;

	system ("pause");
	return 0;
}

