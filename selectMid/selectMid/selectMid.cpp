#include <string.h>
#include <stdlib.h>

#define SWAP(a, b) \
	do { \
		a = a ^ b; \
		b = a ^ b; \
		a = a ^ b; \
			} while (0)

int SelectMid(const int* arr, int num, int index)
{
	int arrSize = sizeof(int) * num;
	int* swap = (int*)(malloc(arrSize));
	memcpy(swap, arr, arrSize);
	int i, j, k, res;
	if (num < 10) {
		for (i = 1; i < num; i++) {
			for (j = 0; j < i; j++) {
				if (swap[i] < swap[j]) SWAP(swap[i], swap[j]);
			}
		}
		res = swap[index];
		free(swap);
		return res;
	}
	int arrNum = (num % 5) ? num / 5 + 1: num / 5;
	int *midArr = (int*)malloc(sizeof(int) * arrNum);
	for (i = 0; i < arrNum; i++) {
		for (j = 1; j < 5 && i * 5 + j < num; j++) {
			for (k = 5 * i; k < (5 * i + j); k++) {
				if (swap[k] > swap[5 * i + j]) SWAP(swap[k], swap[5 * i + j]);
			}
		}
		midArr[i] = swap[((k - 5 * i) >> 1) + 5 * i];
	}
	res = SelectMid(midArr, arrNum, (arrNum  - 1 ) / 2);
	i = 0;
	j = num - 1;
	int tmp = swap[i];
	while (i < j) {
		while (i < j && swap[j] > res) {
			j--;
		}
		swap[i] = swap[j];
		while (i < j && swap[i] <= res) {
			i++;
		}
		swap[j] = swap[i];
	}
	swap[i] = tmp;
	k = tmp > res ? i - 1 : i;
	if (k == index) {
		free(swap);
		return res;
	}
	else if (k < index) {
		res = SelectMid(swap + k + 1, num - k - 1, index - k - 1);
	}
	else{
		res = SelectMid(swap, k + 1, index);
	}
	free(swap);
	free(midArr);
	return res;
}