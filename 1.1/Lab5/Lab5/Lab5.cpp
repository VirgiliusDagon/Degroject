// Lab5.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	cout << "������� ������ �������" << endl;
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

	cout << "\n����������� �� ������ ������� ������� = " << a << endl;


	cout << "\n� ������ �������� ������� �������� �� ������ ��������, �� ������ �� ��������.\n" << endl;

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


	cout << "\n����� ������� ��������� ������� = " << s << endl;

	delete [] mas;

	system ("pause");
	return 0;
}

