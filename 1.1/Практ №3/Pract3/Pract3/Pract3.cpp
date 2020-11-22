#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");
	
	double x, y, r1, r2, y2, ask;

	do
	{
		cout << "Введите х = ";
		cin >> x;
		cout << "Введите y = ";
		cin >> y;

		r1 = sqrt(pow(x, 2) + pow(y, 2));
		r2 = sqrt(pow(x - 2, 2) + pow(y, 2));
		y2 = 2 + x;

		if (r1<=1 || r2<=1 || (x<=0 && y>=0 && y<=y2))
		cout << "Попал" << endl;
		else 
		cout << "Не попал" << endl;

		cout << "Нажмите клавишу Esc, чтобы выйти. Любую другую, чтобы продолжить." << endl;
		ask = getch();
	}
	while (ask != 27);

	return 0;
}

