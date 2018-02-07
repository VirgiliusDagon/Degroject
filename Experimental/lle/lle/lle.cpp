#include <iostream>
#include <cstdio>

using namespace std;

int main() {
     
	setlocale(LC_CTYPE, "rus");

	char str;

	for (int i = 0; i < 128; i++) {
		str = i;
		cout << str << " " << (int)str << endl;
	}
	
	system("pause");
    return 0;
}