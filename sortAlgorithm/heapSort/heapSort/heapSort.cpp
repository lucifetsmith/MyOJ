#include <stdlib.h>
#include <string.h>

#define SWAP(a, b) \
	do { \
		a = a ^ b; \
		b = a ^ b; \
		a = a ^ b; \
	} while (0)
#define MIN_NUM		0x80000001

void MaxHeapify(int* arr, int num, int root = 0)
{
	int leftChild = 2 * root + 1;
	int rightChild = 2 * root + 2;
	if (leftChild >= num) {
		return;
	}
	if (rightChild < num && arr[rightChild] > arr[leftChild] && arr[rightChild] > arr[root]) {
		SWAP(arr[rightChild], arr[root]);
		MaxHeapify(arr, num, rightChild);
	}
	else if (arr[leftChild] > arr[root]) {
		SWAP(arr[leftChild], arr[root]);
		MaxHeapify(arr, num, leftChild);
	}
}

void InitMaxTree(int* arr, int num, int root = 0)
{
	int leftChild = 2 * root + 1;
	int rightChild = 2 * root + 2;
	if (leftChild >= num) {
		return;
	}
	InitMaxTree(arr, num, leftChild);
	InitMaxTree(arr, num, rightChild);
	MaxHeapify(arr, num, root);
}

void heapSort(int* arr, int num)
{
	if (!arr) {
		return;
	}
	int arrLen = sizeof(int) * num;
	int* maxTree = static_cast<int*>(malloc(arrLen));
	if (!maxTree) {
		return;
	}
	memcpy(maxTree, arr, arrLen);
	InitMaxTree(maxTree, num);
	for (int i = 0; i < num; i++) {
		arr[i] = maxTree[0];
		maxTree[0] = MIN_NUM;
		MaxHeapify(maxTree, num);
	}
	free(maxTree);
	return;
}



void HeapAdjust(int arr[], int i, int nLength)
{
	int child = 0;
	for (; 2 * i + 1 < nLength; i = child) {
		child = 2 * i + 1;
		if (child + 1 < nLength && arr[child] > arr[child + 1]) {
			child++;
		}
		if (arr[i] > arr[child]) {
			SWAP(arr[i], arr[child]);
		}
		else {
			break;
		}
	}
}


void HeapSort(int arr[], int length)
{
	int i = 0;
	for (i = length / 2 - 1; i >= 0; i--) {
		HeapAdjust(arr, i, length);
	}
	for (i = 1; i < length; i++) {
		SWAP(arr[length - i], arr[0]);
		HeapAdjust(arr, 0, length - i);
	}
}