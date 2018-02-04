#pragma once

#include <iostream>

void FibonacciSequence(int n) {

	unsigned int t1 = 0, t2 = 1, temp;

	for (int i = 0; i < n; i++) {
		temp = t1 + t2;
		std::cout << temp << " ";
		t1 = t2;
		t2 = temp;
	}
}