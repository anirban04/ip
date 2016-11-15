#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

void getMaxDiff(int* arr, int size, int* a, int* b) {
  	if (size < 2)
		return;

  	int l = arr[0];
	int r = arr[1];
	for (int i = 2; i < size; i++) {
		if (arr[i] < MIN(l, r)) {
			if (l < r)
				l = arr[i];
			else
				r = arr[i];
		}
		else if(arr[i] > MAX(l, r)) {
			if (l > r)
				l = arr[i];
			else
				r = arr[i];
		}
	}

	int first = l;
	int second = r;

	for (int i = 0; i < size; i++) {
		if (arr[i]== first) {
			*a = first;
			*b = second;
			return;
		}
		if(arr[i] == second) {
			*a = second;
			*b = first;
			return;
		}
	}
}

int main() {
	int maxa = 0;
	int maxb = 0;
	int arr[6] = {-3, 2, 1, 5, 8, 100};
	getMaxDiff(arr, 6, &maxa, &maxb);
	printf("%d : %d\n", maxa, maxb);
}
