// ��������� y=b+kx.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	float x1, x2, y1, y2, b, k;

	cout<< "������� X1 = ";
	cin>> x1;
	cout<< "������� Y1 = ";
	cin>> y1;
	cout<< "������� X2 = ";
	cin>> x2;
	cout<< "������� Y2 = ";
	cin>> y2;

	k=(y1-y2)/(x1-x2);
	b=(y2*x1 - y1*x2)/(x1-x2);

	cout<< "y = " << b << " + " << k << "x" << endl;

	system ("pause");

	return 0;
}

