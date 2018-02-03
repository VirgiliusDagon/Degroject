// Ukaz.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Clason
{
private:
	int j;
public:
	Clason (int j)
	{
		this->j = j * 2;

		cout << this->j << endl;
	}
	~Clason ()
	{
		cout << "Destroy " << j << endl;
		system("pause");
	}
};

int func_p (int *);
int func_v (int);
int func_r (int &);

int _tmain(int argc, _TCHAR* argv[])
{

	Clason obj1 (1);
	Clason obj2 (2);

	int a = 10;

	/*cout << func_p(&a) << endl;
	cout << a << endl << endl;

	cout << func_v(a) << endl;
	cout << a << endl << endl;

	cout << func_r(a) << endl;
	cout << a << endl << endl;*/


	return 0;
}

int func_p (int *var)
{
	return *var *= 5;
}

int func_v (int var)
{
	return var *= 5;
}

int func_r (int &var)
{
	return var *= 5;
}