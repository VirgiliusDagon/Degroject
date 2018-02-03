
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "merge.h"
#include "vmerge.h"
#include "qs.h"

using namespace std;

void Vyvod (int *, int);
void Randomizer (int *, int);

//Сортировка пузырьком
void Bubble (int *mas, int n) {
	cout << "Bubble sort" << endl;

	int t1 = clock();
	int b;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++) 
			if (mas[j] > mas[j + 1]) {
				b = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = b;
			}
	int t2 = clock();
	cout << "Bubble time = " << t2 - t1 << endl;
}

//Cортировка выбором
void Selection (int *mas, int n){
	cout << "Selection sort" << endl;

	int t1 = clock();
	int b;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) 
			if (mas[i] > mas[j]) {
				b = mas[i];
				mas[i] = mas[j];
				mas[j] = b;
			}
	int t2 = clock();
	cout << "Selection time = " << t2 - t1 << endl;
}

//Сортивровка модифицированным выбором
void ModSelection (int *mas, int n) {
	cout << "Modified Selection sort" << endl;

	int t1 = clock();
	int min;
	int b;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i; j < n; j++)
			if (mas[min] > mas[j]) 
				min = j;

		b = mas[i];
		mas[i] = mas[min];
		mas[min] = b;
	}
	int t2 = clock();
	cout << "ModSelection time = " << t2 - t1 << endl;
}

//Сортировка вставкой
void Insertion (int *mas, int n) {
	cout << "Insertion sort" << endl;

	int t1 = clock();
	int b;
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0; j--)
			if (mas[j - 1] > mas[j]) {
				b = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = b;
		}
	int t2 = clock();
	cout << "Insertion time = " << t2 - t1 << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int	checks = 0,
		swaps = 0,
		n;

	cout << "Amount of elements = ";
	cin >> n;

	srand(time(NULL));

	int *mas = new int [n];

	Randomizer(mas, n); //Присвоение ранд. значений элементам массива
	//Vyvod(mas, checks, swaps, n); //Вывод значений элементов массива

	//Сортировка пузырьком
	//Bubble (mas, n);
	//Vyvod(mas,n);
	//Randomizer(mas, n);

	//Сортировка выбором
	//Selection (mas, n);
	//Vyvod(mas, n);
	//Randomizer(mas, n);

	//Сортировка модифициорованным выбором
	//ModSelection (mas, n);
	//Vyvod(mas, n);
	//Randomizer(mas, n);
	
	//Сортировка вставкой
	//Insertion (mas, n);
	//Vyvod(mas, n);
	Randomizer(mas, n);

	//Merge
	MergeSort (mas, n);
	//Vyvod(mas, n);
	Randomizer(mas, n);
	
	//QuickSort
	quickSort(mas, n);
	//Vyvod(mas, n);
	//VMerge
	/*t1 = clock();
	cout << "VMerge " << endl;
	VMergeSort (mas, n);
	t2 = clock();
	cout << "VMerge time = " << t2 - t1 << endl;*/

	delete [] mas;
	system("pause");
	return 0;
}

void Vyvod (int *mas, int n) {
	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";
	cout << endl;
	cout << endl;
}

void Randomizer (int *mas, int n) {
	for (int i = 0; i < n; i++)
		mas[i] = rand()%100;
}