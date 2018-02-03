// Lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	double x1, x2, h, a, b, c, f, y;

	cout << "x1 = ";
	cin >> x1;
	cout << "x2 = ";
	cin >> x2;
	cout << "h = ";
	cin >> h;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	if (x1 < 3 && b != 0) {
		cout << "\n y(x) = a*x^2 - b*x + c" << endl;
		for (f = x1; f <= x2; f = f + h) {
			y = a*f*f - b*f + c;
			cout << "\n y(" << f << ") = " << y << endl;
		}
	}
	else if (x1 > 3 && b == 0) {
		cout << "\n y(x) = (f - a)/(f - c)" << endl;
		for (f = x1; f <= x2; f = f + h) {
			y = (f - a)/(f - c);
			cout << "\n y(" << f << ") = " << y << endl;
		}
	}
	else {
		cout << "\n y(x) = x/c" << endl;
		for (f = x1; f <= x2; f = f + h) {
			y = f/c;
			cout << "\n y(" << f << ") = " << y << endl;
		}
	}


	system("pause");

	return 0;
}

