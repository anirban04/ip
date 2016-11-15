#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int* arr, int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int getClass(int i) {
	if(i < 3)
		return -1;
	if (i < 6)
	  	return 0;
	return 1;
}

void getCount (int* arr, int len, int* small, int* med, int* large) {
	for (int i = 0; i < len; i++) {
	  	int class = getClass(arr[i]);
		if (class == -1)
			*small = *small + 1;
		else if (class == 0)
		  	*med = *med + 1;
		else
			*large = *large + 1;
	}
}

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void sort(int* arr, int len) {
	int small = 0;
	int med = 0;
	int large = 0;
	int sIdx = 0;
	int mIdx = 0;
	int lIdx = 0;;
	getCount(arr, len, &small, &med, &large);
	mIdx = small;
	lIdx = small + med;

	int i = 0;
	while(i < small) {
		int class = getClass(arr[i]);
		if (class == -1) {
			sIdx++;
			i++;
		}
		else if (class == 0) {
			swap(arr, i, mIdx);
			mIdx++;
		}
		else {
			swap(arr, i, lIdx);
			lIdx++;
		}
	}

	if (mIdx < small + med) {
		i = mIdx;
		while(i < small + med) {
			int class = getClass(arr[i]);
			if (class == 0) {
				mIdx++;
				i++;
			}
			else {
				swap(arr, i, lIdx);
				lIdx++;
			}
		}	
	}
}

int main() {
	int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	printArr(arr, 10);
	sort(arr, 10);
	printArr(arr, 10);
}
