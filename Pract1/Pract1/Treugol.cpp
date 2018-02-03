#include <iostream>
#include "math.h"
using namespace std;
 
 int main() {
     
	setlocale(LC_CTYPE, "rus");

	double a, b, c, A, B, S, pi;

	pi=3.14;

	cout<<"Введите значение катета а = ";
	cin>> a;
	cout<<"Введите значение площади S = ";
	cin>> S;

	b=(2*S)/a;
	c=sqrt(pow(a,2) + pow(b,2));
	A=180/pi*acos(a/c);
	B=180/pi*acos(b/c);

	cout<< "Угол А = " << A << endl;
	cout<< "Угол В = " << B << endl;
	cout<< "Гипотенуза с = " << c << endl;
	cout<< "Катет b = " << b << endl;

	system("pause");

    return 0;
}
