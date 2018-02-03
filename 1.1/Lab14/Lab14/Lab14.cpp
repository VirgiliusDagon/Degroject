// Lab14.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Pair
{
public:
	virtual void add () = 0;
	virtual void sub () = 0;
	virtual void mul () = 0;
	virtual void div () = 0;

};

class FuzzyNum : public Pair
{
private:
	double a;
	double b;
	double e;
public:
	FuzzyNum ()
	{
		cout << "A = ";
		cin >> a;
		cout << "B = ";
		cin >> b;
		cout << "e = ";
		cin >> e;
	}
	~FuzzyNum () {}

	void getNum ()
	{
		cout << "\n����� � = " << a << " +- " << e << endl;
		cout << "����� B = " << b << " +- " << e << endl << endl;
		return;
	}

	void add ()
	{
		cout << "����� ����� � � � = " << a + b << " +- " << 2*e << endl;
		return;
	}

	void sub ()
	{
		cout << "�������� � � � = " << a - b << " +- " << 2*e << endl;
		return;
	}

	void mul ()
	{
		cout << "������������ � � � = " << a * b << " +- " << e*a + e*b + 2*e << endl;
		return;
	}

	void div ()
	{
		cout << "������� � � � = " << a/b << " +- " << a/(e + b) - e/(e + b) << endl;
		return;
	}
};

class Fraction : public Pair
{
private:
	short int a;
	short int b;
	unsigned long int af;
	unsigned long int bf;
	int ra;
	int rb;
public:

	Fraction ()
	{
		cout << "A = ";
		cin >> a;
		cout << "a = ";
		cin >> af;
		ra = 10;
		while (af / ra >= 1)
			ra *= 10;
		cout << "B = ";
		cin >> b;
		cout << "b = ";
		cin >> bf;
		rb = 10;
		while (bf / rb >= 1)
			rb *= 10;
	}
	~Fraction () {}

	void getNum ()
	{
		cout << "\n����� � = " << a << "." << af << endl;
		cout << "����� B = " << b << "." << bf << endl << endl;
		return;
	}

	void add ()
	{
		cout << "����� ����� � � � = " << (a + b) + (double)bf/rb + (double)af/ra << endl;
		return;
	}

	void sub ()
	{
		cout << "�������� � � � = " << (a - b) + (double)af/ra - (double)bf/rb << endl;
		return;
	}

	void mul ()
	{
		cout << "������������ � � � = " << (a + (double)ra/af)*(b + (double)rb/bf) << endl;
		return;
	}

	void div ()
	{
		cout << "������� � � � = " << (a + (double)ra/af)/(b + (double)rb/bf) << endl;
		return;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	FuzzyNum nech;

	nech.getNum ();
	nech.add ();
	nech.sub ();
	nech.mul ();
	nech.div ();

	cout << endl;

	Fraction drob;

	drob.getNum ();
	drob.add ();
	drob.sub ();
	drob.mul ();
	drob.div ();

	system ("pause");
	return 0;
}

