// Lab9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

int Counter (int *, int);
void Counter (int *, int, int &, int &);

int _tmain(int argc, _TCHAR* argv[]) {

	setlocale (LC_ALL, "rus");

	int i, n, s1 = 0, s2 = 0;

	cout << "Введите размерность массива ";
	cin >> n;

	int *mas = new int [n];

	srand (time (NULL));
	for (i = 0; i < n; i++) {
		mas[i] =  rand ()% 10 - 5;
		cout << mas[i] << "\t";
	}

	cout << "\nПроизведение четных элементов " << Counter (mas, n) << endl;

	Counter (mas, n, s1, s2);

	cout << "Сумма до первого 0-го элемента " << s1 << endl;
	cout << "Сумма после последнего 0-го элемента " << s2 << endl;

	system ("pause");
	return 0;
}

int Counter (int *mas ,int n) {

	int product = 1;

	for (int i = 1; i < n; i += 2)
		product *= mas[i];

	return product;
}

void Counter (int *mas, int n, int &s1, int &s2) {
	
	int i;

	for (i = 0; i < n; i++) {
		if (mas[i] == 0)
			break;
		s1 += mas[i];
	}

	for (i = n - 1; i >= 0; i--) {
		if (mas[i] == 0)
			break;
		s2 += mas[i];
	}
	return;
}