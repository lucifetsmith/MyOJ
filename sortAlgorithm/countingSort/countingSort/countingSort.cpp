#include <string.h>
#include <stdlib.h>

void countingSort(const int* arr, int* res, int len)
{
	int i = 0, max = 0;
	int arrSize = len * sizeof(int);
	for (i = 0; i < len; i++) {
		if (arr[i] > max) max = arr[i];
	}
	int countArrSize = (max + 1) * sizeof(int);
	int *countingArr = static_cast<int*>(malloc(countArrSize));
	if (!countingArr) return;
	memset(countingArr, 0, countArrSize);
	for (i = 0; i < len; i++) {
		countingArr[arr[i]]++;
	}
	for (i = 1; i < max + 1; i++) {
		countingArr[i] += countingArr[i - 1];
	}
	for (i = len - 1; i >= 0; i--) {
		countingArr[arr[i]]--;
		res[countingArr[arr[i]]] = arr[i];
	}
	return;
}