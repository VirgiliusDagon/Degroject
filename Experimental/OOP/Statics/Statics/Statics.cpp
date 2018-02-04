// Statics.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Class.h"
#include <vector>

using namespace std;

int main()
{
	char ask[10];
	vector<Player> vec;

	do {
		vec.push_back (Player());

		cout << "Exit to escape ";
		cin >> ask;
	} while (strcmp(ask, "exit"));

	for (int i = 0; i < (int) vec.size(); i++)
		cout << vec[i].get_id() << endl;

	vec.erase(vec.begin()+1);

	for (int i = 0; i < (int)vec.size(); i++)
		cout << vec[i].get_id() << endl;

	system("pause");
    return 0;
}

