// Pract7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

int Max (int **, int);
int Min (int **, int);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	int pos = 0, sum = 0;

	int **mas = new int *[14];
	for (int i = 0; i < 14; i++)
		mas[i] = new int [14];

	srand(time(NULL));

	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 14; j++) 
		{
			mas[i][j] = rand() %100 - 50;
			if (mas[i][j] > 0)
				pos++;
			if (i < j)
				sum += mas[i][j];
		}

	cout << "Cумма элементов ниже главной диагонали " << sum << endl;
	cout << "Количество положительных элементов " << pos << endl << endl;

	for (int i = 0; i < 14; i++)
	{
		cout << "Максимальное значение " << Max(mas, i) << " Минимаьное значение " << Min(mas, i) << endl;	
	}
	system ("pause");
	return 0;
}

int Max (int **mas, int i)
{
	int max = mas[i][0];

	for (int j = 0; j < 14; j++)
		if (max < mas[i][j])
			max = mas[i][j];

	return max;
}

int Min (int **mas, int i)
{
	int min = mas[i][0];

	for (int j = 0; j < 14; j++)
		if (min > mas[i][j])
			min = mas[i][j];

	return min;
}
