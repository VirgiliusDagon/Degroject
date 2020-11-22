#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	float x, y;

	cout<< "¬ведите значение x = ";
	cin>> x;

	if (-4 < x && x < -3) {
		cout << "y = "<< 4 + x <<endl;
	} else if (x == -3) {
		cout << "1 <= y <= -1" << endl;
	} else if (-3 < x && x <= -2) {
		cout << "y = " << -4 - x << endl;
	} else if (-2 < x && x <= -1) {
		cout << "y = " << -x << endl;
	} else if (-1 < x && x <= 0) {
		cout << "y = " << -1 << endl;
	} else if (0 < x && x <= 1) {
		cout << "y = " << -1 + x << endl;
	} else if (1 < x && x <= 2) {
		cout << "y = " << -3 + x << endl;
	} else if (2 < x && x <= 3) {
		cout << "y = " << -1 << endl;
	} else if (3 < x && x < 4) {
		cout << "y = " << -4 + x << endl;
	} else if ( x == 4) {
		cout << "0 <= y <= 2" << endl;
	} else if (4 < x && x <= 5) {
		cout << "y = " << 10 - 2*x << endl;
	} else {
		cout << "y = 0" << endl;
	}



	system ("pause");

	return 0;
}
