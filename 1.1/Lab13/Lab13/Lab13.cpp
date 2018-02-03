// Lab13.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Line
{
private:
	double k;
	double b;
public:
	Line ()
	{
		cout << "Введите коэфицент k ";
		cin >> k;
		cout << "Введите коэфицент b ";
		cin >> b;
		cout << setprecision (2) << "Уравнение заданной прямой y = " << k << "*x + " << b << endl;
	}
	~Line () {}

	void cross ()
	{
		cout << "Прямая пересекает оси" << endl;
		if (k == 0)
			cout << "Прямая паралельна оси Х" << endl;
		else
			cout << "Х в точке [" << -b/k << ", 0]" << endl;
			cout << "Y в точке [0, " << b << "]" << endl << endl;
		return;
	}

	friend bool operator != (Line line1,Line line2)
	{
		if (line1.k*line2.k + 1 != 0)
		{
			cout << "Угол между прямыми равен " << (tan ((abs(line2.k - line1.k))/(1+line1.k*line2.k)))*180/3.14 << endl << endl;
			return 1;
		}
		else
		{
			cout << "Прямые перпендикулярны" << endl << endl;	
			return 0;
		}
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	Line line1;
	line1.cross ();
	Line line2;
	line2.cross ();

	if (line1 != line2);

	system ("pause");
	return 0;
}

