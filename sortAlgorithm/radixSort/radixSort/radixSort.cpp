#include <string.h>
#include <stdlib.h>

/* 
	e.g.
	1010100001010010
		 |		|
	  endBit startBit
*/
void CountingSort(unsigned* arr, int num, int startBit, int endBit)
{
	int i;
	unsigned mask = 0;
	for (i = startBit; i <= endBit; i++) {
		mask |= (1 << i);
	}
	int shadowSize = sizeof(unsigned) * num;
	unsigned* shadow = (unsigned*)(malloc(shadowSize));
	unsigned max = 0;
	memcpy(shadow, arr, shadowSize);
	for (i = 0; i < num; i++) {
		if (((shadow[i] & mask) >> startBit) > max) {
			max = ((shadow[i] & mask) >> startBit);
		}
	}
	int cntArrSize = sizeof(int) * (max + 1);
	int* cntArr = (int*)(malloc(cntArrSize));
	memset(cntArr, 0, cntArrSize);
	for (i = 0; i < num; i++) {
		cntArr[((shadow[i] & mask) >> startBit)]++;
	}
	for (i = 1; i < max + 1; i++) {
		cntArr[i] += cntArr[i - 1];
	}
	for (i = num - 1; i >= 0; i--) {
		cntArr[((shadow[i] & mask) >> startBit)]--;
		arr[cntArr[((shadow[i] & mask) >> startBit)]] = shadow[i];
	}
	free(shadow);
	free(cntArr);
}

void RadixSort(unsigned* arr, int num)
{
	int bitGop = 8;
	int startBit, endBit;
	for (startBit = 0, endBit = 0; startBit < 32; startBit += bitGop) {
		endBit = (startBit + bitGop - 1 < 32) ? startBit + bitGop - 1 : 31;
		CountingSort(arr, num, startBit, endBit);
	}
}