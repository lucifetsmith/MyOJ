#include <stdlib.h>
#include <string.h>

void mergeSort(int* arr, int start, int end, int **ppSwapBuf)
{
	if (start >= end || !ppSwapBuf) {
		return;
	}
	int mid = (start + end) / 2;
	int arrLen = sizeof(int) * (end - start + 1);
	int *swapBuf = *ppSwapBuf;
	if (!swapBuf) {
		swapBuf = static_cast<int*>(malloc(arrLen));
		*ppSwapBuf = swapBuf;
	}
	mergeSort(arr, start, mid, &swapBuf);
	mergeSort(arr, mid + 1, end, &swapBuf);
	memcpy(swapBuf + start, arr + start, arrLen);
	int i = start;
	int j = mid + 1;
	int index = start;
	while (i <= mid && j <= end) {
		if (swapBuf[i] < swapBuf[j]) {
			arr[index++] = swapBuf[i++];
		}
		else {
			arr[index++] = swapBuf[j++];
		}
	}
	while (i <= mid) {
		arr[index++] = swapBuf[i++];
	}
	while (j <= end) {
		arr[index++] = swapBuf[j++];
	}
}