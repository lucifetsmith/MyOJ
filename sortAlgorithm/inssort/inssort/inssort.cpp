#define SWAP(a, b)	\
	do {\
		a = a ^ b;\
		b = a ^ b;\
		a = a ^ b;\
		} while (0)

void inssort(int* arr, const int num)
{
	int i, j;
	for (i = 1; i < num; i++) {
		for (j = 0; j < i; j++) {
			if (arr[i] <= arr[j]) {
				SWAP(arr[i], arr[j]);
			}
		}
	}
}