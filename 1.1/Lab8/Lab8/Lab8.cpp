// Lab8.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

void Max (int * ,int, int &);
void Min (int * ,int, int &);
void Clear (int *, int &);

int _tmain(int argc, _TCHAR* argv[]) {

	setlocale (LC_ALL, "rus");

	int n, i;

	cout << "¬ведите размерность массива ";
	cin >> n;

	int *mas = new int [n];

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		mas[i] = rand () % 100 - 50;
		cout << mas[i] << "\t";
	}
	  
	int max = mas[0], min = mas[0];

	Max (mas, n, max);
	Min (mas, n, min);
	cout << "\nMax = " << max << endl; 
	cout << "Min = " << min << endl;

	for (i = 0; i < n; i++) {
		if (mas[i] == max) {
			mas[i] = min;
			continue;
		}
		if (mas[i] == min)
			mas[i] = max;
	}

	Clear (mas, n);
	for (i = 0; i < n; i++)
		cout << mas[i] << "\t";
	cout << endl;

	delete [] mas;
	system ("pause");
	return 0;
}

void Max (int *mas, int n, int &max) {
	
	for (int i = 1; i < n; i++)
		if (max < mas[i])
			max = mas[i];
	return;
}

void Min (int *mas, int n, int &min) {

	for (int i = 1; i < n; i++) 
		if (min > mas[i])
			min = mas[i];
	return;
}

void Clear (int *mas, int &n) {

	for (int i = 0; i < n; i++) {
		while (mas[i] % 2 != 0 && i < n) {
			for (int j = i; j < n; j++)
				mas[j] = mas[j+1];
			n--;
		}	
	}		
	return;
}