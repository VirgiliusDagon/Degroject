// Vectoryno.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	vector<int> vec;

	cin >> n;

	for(int i = 0; i < n; i++) 
	{
		vec.push_back(i);
		cout << vec[i] << " ";
	}
	
	//vec.erase(vec.begin() + 4);

	for(int i = 0; i < vec.size(); i++) 
	{
		cout << vec[i] << " ";
	}

	cout << "\nVec size " << vec.size() << endl;
	system("pause");
	return 0;
}

