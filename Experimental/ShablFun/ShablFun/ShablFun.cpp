// ShablFun.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

template <class T>
int count (T** , int , int);

int _tmain (int argc, _TCHAR* argv[]) {

	setlocale (LC_ALL, "rus");

	int n, m, i, j;

	cout << "Столбцы ";
	cin >> n;
	cout << "Строки ";
	cin >> m;

	srand(time(NULL));

	int** mas = new int* [n];
	for (i = 0; i < n; i++) {
		mas[i] = new int [m];
		for (j = 0; j < m; j++)
		mas[i][j] = rand()% 10 - 5;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) 
			cout << mas[i][j] << "\t";
			cout << endl;
	}
	cout << endl;

	double** masd = new double* [n];
	for (i = 0; i < n; i++) {
		masd[i] = new double [m];
		for (j = 0; j < m; j++)
		masd[i][j] = rand()% 100/ 4.5;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) 
			cout << setw(5) << setprecision(3) << masd[i][j] << "\t";
			cout << endl;
	}

	cout << "Кол-во нулевых элементов равно " << count (mas, n, m) <<endl;
	
	cout << "Кол-во нулевых вещественных элементов " << count (masd, n, m) << endl;

	for (i = 0; i < n; i++)
		delete [] mas[i];
	delete [] mas;

	system ("pause");
	return 0;
}

template <class T>
int count (T** mas, int n, int m) {
	int k = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mas[i][j] == 0)
				k++;

	return k;
}
	//int s1, sum, n, m;
	//sum = 0;

	//int*  str1 = new int [n];
	//for (s1 = 0; s1 < n; s1++) {
	//	for (int i = 0; i < n; i++)
	//		for (int j; j < n; j++)
	//			sum += mas[i][j];
	//	str1[s1] = sum;
	//}
