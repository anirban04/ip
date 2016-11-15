#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

void getMaxDiff(int* arr, int size, int* a, int* b) {
  	int minStart = 0;
	int maxEnd = 0;

	int st = 0;
	int en = 1;
	int maxDiff = arr[1] - arr[0];
	
	if (size <= 1)
		return;

	for (int i = 2; i < size; i++) {
		if (arr[i] < arr[st]) {
			st = i;
			en = i;
		}
		else if (arr[i] > arr[en]) {
			en = i;
		}

		if (maxDiff < arr[en] - arr[st]) {
			maxDiff = arr[en] - arr[st];
			minStart = st;
			maxEnd = en;
		}
	}
	*a = minStart;
	*b = maxEnd;
}

int main() {
	int maxa = 0;
	int maxb = 0;
	int arr[7] = {2, 3, 10, 6, 4, 8, 1};
	getMaxDiff(arr, 6, &maxa, &maxb);
	printf("%d : %d\n", maxa, maxb);
}
