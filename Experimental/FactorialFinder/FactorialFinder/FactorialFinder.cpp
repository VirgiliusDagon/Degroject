#include "stdafx.h"
#include <iostream>
#include "FactorialFinder.h"
#include <ctime>

using namespace std;

int main()
{
	long long n;

	cout << "Enter number to fact. ";
	cin >> n;

	cout << FactorialFinder(n) << endl;
	
	system("pause");
    return 0;
}

