/* 
	Чертов сортировочный монстр
*/


#include "stdafx.h"
#include <iostream>

void Merge (int *mas, int *buf, int left, int right) {

	int m = (right + left) / 2,
		cl = left,
		cr = m + 1;
	
	for (int i = 0; i <= right-left; i++) {
		if (cl > m)
			buf[i] = mas[cr++];
		else if (cr > right)
			buf[i] = mas[cl++];
		else if (mas[cl] > mas[cr])
			buf[i] = mas[cr++];
		else
			buf[i] = mas[cl++];
	}

	for (int i = 0; i + left <= right; i++)
		mas[i + left] = buf[i];
}

void MergeSortRecursion(int *mas, int *buf, int left, int right) {
	int b;

	if (right == left)
		return;
	if (right - left == 1) {
		if (mas[right] < mas[left]) {
			b = mas[left];
			mas[left] = mas[right];
			mas[right] = b;
		}
		return;
	}
	MergeSortRecursion(mas, buf, left, (right + left) / 2);
	MergeSortRecursion(mas, buf, (right + left) / 2 + 1, right);
	Merge (mas, buf, left, right);
}

void MergeSort(int *mas, int right) {
	std::cout << "Merge " << std::endl;
	int t1 = clock();
	int *buf = new int[right];
	int left = 0;
	MergeSortRecursion(mas, buf, left, right - 1);
	delete[] buf;

	int t2 = clock();
	std::cout << "Merge Time = " << t2 - t1 << std::endl;
}