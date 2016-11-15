#include<stdio.h>
#include<stdlib.h>

int square(int i) {
	return i * i;
}

int* getSquaresOfSorted(int* arr, int size) {
	int* res = malloc(size * sizeof(int));
	int i, j;

	for (i = 0; i < size; i++) {
		if (arr[i] >= 0)
			break;
	}
	
	int resIdx = 0;
	if (arr[i] == 0) {
		res[resIdx] = 0;
		resIdx++;
		i++;
		j = i - 2;
	}
	else {
		j = i - 1;
	}

	while(j >= 0 || i < size) {
		while(j >= 0 && i < size) {
			if ((-1 * arr[j]) <= arr[i]) {
				res[resIdx] = square(arr[j]);
				resIdx++;
				j--;
			}
			else {
				res[resIdx] = square(arr[i]);
				resIdx++;
				i++;
			}
		}
		while(j >= 0) {
			res[resIdx] = square(arr[j]);
			resIdx++;
			j--;
		}
		while(i < size) {
			res[resIdx] = square(arr[i]);
			resIdx++;
			i++;
		}
	}
	return res;
}

int main() {
  	int arr[10] = {-10, -5, -3, -2, 0, 1, 3, 4, 6, 8};
	int *res = getSquaresOfSorted(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", res[i]);
	}
}
