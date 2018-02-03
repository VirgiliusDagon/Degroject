// Lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <Windows.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	int i, j, count, key;
	char ask;

	count = 1;

	struct MARSH {
		char start[10];
		char finish[10];
		char num[5];
	};

	MARSH *spisok = new MARSH[10], buf;

	int cp = GetConsoleCP();

	for (i = 0; i < 10; i++) {
		cout << "Введите начальную точку маршрута ";
		SetConsoleCP(1251);
		cin >> spisok[i].start;
		SetConsoleCP(cp);
		cout << "Введите конечную точку маршрута ";
		SetConsoleCP(1251);
		cin >> spisok[i].finish;
		SetConsoleCP(cp);
		cout << "Введите номер маршрута ";
		cin >> spisok[i].num;
		cout << "Продолжить ввод? (Y/N) ";
		cin >> ask;
		if (ask == 'n')
			break;
		count++;
	}

	for (i = 0; i < count; i++)
		for (j = i + 1; j < count; j++)
			if (atoi(spisok[i].num) > atoi(spisok[j].num)) {
				buf = spisok[i];
				spisok[i] = spisok[j];
				spisok[j] = buf;
			}

	for (i = 0; i < count; i++) {
		cout << spisok[i].num << "  ";
		cout << spisok[i].start << "  ";
		cout << spisok[i].finish << endl << endl;
	}

	cout << "Введите номер интересующего вас маршрута " << endl;
	
	cin >> key;

	int f = 0;
	for (i = 0; i < count; i++)
		if (atoi(spisok[i].num) == key) {
			f++;
			cout << "Информация об указанном маршруте: " << endl;
			cout << spisok[i].num << "  ";
			cout << spisok[i].start << "  ";
			cout << spisok[i].finish << endl << endl;
		}
	if (f == 0)
		cout << "Указанный маршрут не найден" << endl;

	delete [] spisok;
	
	system ("pause");
	return 0;
}

