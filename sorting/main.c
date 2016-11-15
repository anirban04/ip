#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void sequentialSort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
	  	int minIdx = i;
		for (int j = i; j < len; j++) {
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		if (minIdx != i)
			swap(arr, i, minIdx);
	}
}

void shiftRight(int* arr, int i, int j) {
	while(j >= i) {
		arr[j + 1] = arr[j];
		j--;
	}
}

void insertionSort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				shiftRight(arr, j, i - 1);
				arr[j] = temp;
			}
		}
	}
}

void bubbleSort(int *arr, int len) {
	for (int i = len - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}
}

int Func( int n )
{
    if( n == 4 )
          return 2;
      else
	    return 2 * Func( n + 1 );
}

int main() {
	//int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//printArr(arr, 10);
	//sequentialSort(arr, 10);
	//insertionSort(arr, 10);
	//bubbleSort(arr, 10);
	//printArr(arr, 10);i
  	printf("%d\n", Func(2));
}
