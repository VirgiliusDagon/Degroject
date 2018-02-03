
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>

void VMerge(int *mas, std::vector<int> buf, int left, int right) {

	int m = (right + left) / 2,
		cl = left,
		cr = m + 1;
	for (int i = left; i <= right; i++) {
		if (cl > m)
			buf.push_back (mas[cr++]);
		else if (cr > right)
			buf.push_back (mas[cl++]);
		else if (mas[cl] > mas[cr])
			buf.push_back (mas[cr++]);
		else
			buf.push_back (mas[cl++]);
	}

	for (int i = 0; i + left <= right; i++)
		mas[i + left] = buf[i];
}

void VMergeSortRecursion(int *mas, std::vector<int> buf, int left, int right) {
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
	VMergeSortRecursion(mas, buf, left, (right + left) / 2);
	VMergeSortRecursion(mas, buf, (right + left) / 2 + 1, right);
	VMerge (mas, buf, left, right);
}

void VMergeSort(int *mas, int right) {

	std::vector<int> buf;
	int left = 0;
	VMergeSortRecursion(mas, buf, left, right - 1);
}