#pragma once

template<class T>
T FactorialFinder(T n) {

	T i = 1;

	while (n > 0) {
		i *= n--;
	}
	
	return i;
}