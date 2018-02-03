#include <iostream>


void QuickSort(int arr[], int left, int right) {

	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */

	while (i <= j) {

		while (arr[i] < pivot)
			i++;

		while (arr[j] > pivot)
			j--;

		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	/* recursion */

	if (left < j)
		QuickSort(arr, left, j);

	if (i < right)
		QuickSort(arr, i, right);
}

void quickSort(int *arr, int right) {

	std::cout << "QuickSort " << std::endl;

	int t1 = clock();
	int left = 0;
	QuickSort(arr, left, right - 1);
	int t2 = clock();
	std::cout << "QuickSort Time = " << t2 - t1 << std::endl;
}