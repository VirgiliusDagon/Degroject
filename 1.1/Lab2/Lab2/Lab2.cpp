#include <iostream>
#include <math.h>

using namespace std;

int	main (){


	setlocale (LC_ALL,"rus");

	const float pi=3.14;
	double a, y1, y2;



	cout<< "������� �������� � = ";
	cin>> a;

	y1=(sin(pi/2 + 3*a))/(1 - sin(3*a - pi));
	y2=1/tan(5*pi/4 + 3*a/2);

	cout<< "�������� y1 = " << y1 << endl;
	cout<< "�������� y2 = " << y2 << endl;

	system ("pause");

		return 0;
}