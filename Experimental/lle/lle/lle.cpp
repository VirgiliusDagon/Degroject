#include <iostream>
#include <ctime>
using namespace std;

#define n 1000000

int main() {
     
	setlocale(LC_CTYPE, "rus");

	int b = 0;

	int *mas = new int [n];

	for (int i = 0; i < n; i++) {
		mas[i] = i;
		cout << mas[i] << " ";
	}
	cout << endl;

	for (int i = 1; i < 10; i++)
		for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--)
		{
			b = mas[j - 1];
			mas[j - 1] = mas[j];
			mas[j] = b;
		}

	for (int i = 0; i < 10; i++)
		cout << mas[i] << " ";

	

	system("pause");
    return 0;
}