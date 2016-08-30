void qsort(int* arr, int low, int high)
{
	if (low >= high){
		return;
	}
	int i = low;
	int j = high;
	int key = arr[low];
	while (i < j) {
		while (i < j && arr[j] >= key) {
			j--;
		}
		arr[i] = arr[j];
		while (i < j && arr[i] <= key) {
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = key;
	qsort(arr, low, i - 1);
	qsort(arr, i + 1, high);
}
