#include "stdafx.h"
#include <iostream>
#include "FibonacciSequence.h"

using namespace std;

int main()
{
	int n;

	cout << "Enter number ";
	cin >> n;

	FibonacciSequence(n);

	cout << endl;
	system("pause");
    return 0;
}

