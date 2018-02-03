// Lab12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Complex {
protected:
	double re;
	double im;
public:
	Complex () {};
	Complex (double _re, double _im) 
	{
		re = _re;
		im = _im;
	}
	~Complex () {};

	void addition (double sec, double sec2)
	{ 
		cout << "\nРезультат " << re + sec << " + i(" << im + sec2 << ")" << endl << endl;
		return;
	}

	void subtraction (double sec, double sec2)
	{
		cout << "\nРезультат " << re - sec << " + i(" << im - sec2 << ")" << endl << endl;
		return;
	}

	void multiplication (double sec, double sec2)
	{
		cout << "\nРезультат " << re * sec - sec2*im << " + i(" << re * sec2 + sec*im << ")" << endl << endl;
		return;
	}

	void division (double sec, double sec2)
	{
		cout << "\nРезультат " << (re*sec + im*sec2)/(sec*sec+sec2*sec2)<< " + i(" << (sec*im - re*sec2)/(sec*sec + sec2*sec2) << ")" << endl << endl;
		return;
	}
};

class ComplexSin : public Complex 
{
public:
	ComplexSin (double _re, double _im) : Complex (_re, _im) {};

	void sin ()
	{
		cout << "\nsin(z) = " << re << " + i" << im << " - (" << re << " + i" << im << ")/3! + ..." << endl << endl;
		return;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	double re, im, sec1, sec2;
	int ask;

	cout << "Введите реальную часть z1 ";
	cin >> re;
	cout << "Мнимую z1 ";
	cin >> im;

	ComplexSin z (re, im);

	do 
	{
		cout << "Сложение - 1 \nВычитание - 2 \nУмножение - 3 \nДеление - 4 \nСинус - 5 \nВыход - 0" << endl;
		cout << "Выберите вариант : ";
		cin >> ask;

		if (ask != 5 && ask !=0)
		{
			cout << "Введите реальную часть z2 ";
			cin >> sec1;
			cout << "Мнимую z2 ";
			cin >> sec2;
		}

		switch (ask)
		{
		case 1 :
			z.addition (sec1, sec2);
			break;
		case 2 :
			z.subtraction (sec1, sec2);
			break;
		case 3 :
			z.multiplication (sec1, sec2);
			break;
		case 4 :
			z.division (sec1, sec2);
			break;
		case 5 :
			z.sin ();
			break;
		}

	} while (ask != 0);

	return 0;
}

