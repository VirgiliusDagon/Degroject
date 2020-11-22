// StringReverse.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	char str[] = "Hellow World", temp;
	int i, j;
	int str_lengh = strlen(str);
	cout << str << endl;
	for (i = 0, j = str_lengh - 1 ; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	cout << str << endl;

	system("pause");
    return 0;
}

