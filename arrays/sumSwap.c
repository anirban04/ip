#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* arr, int len) {

}

int getSum(int* arr, int len) {
	int sum = 0;
  	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}
	return sum;
}

void printArr(int* arr, int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int* getSumSwap(int* arrA, int lenA, int* arrB, int lenB) {
	int idxA = 0;
	int idxB = 0;

	sort(arrA, 6);
	sort(arrB, 4);
	int* res = malloc(sizeof(int) * 2);

	int diff = abs((getSum(arrA, 6) - getSum(arrB, 4)));


	if (diff % 2 > 0)
		return NULL;
	diff = diff / 2;
	//This is basically the diff between the 2 numbers we are trying to find
	
	int a, b;
	int curDiff;
	while(idxA < lenA && idxB < lenB) {
	  	a = arrA[idxA];
		b = arrB[idxB];
		curDiff = abs(b - a);
		if (curDiff == diff) {
			res[0] = b;
			res[1] = a;
			break;
		}
		else if (curDiff < diff)
			idxB++;
		else
		  	idxA++;
	}
	return res;
}
int main() {
	int arrA[6] = {1, 1, 1, 2, 2, 4};
	int arrB[4] = {3, 3, 3, 6};
	
	int* res = getSumSwap(arrA, 6, arrB, 4);
	printf("%d, %d\n", res[0], res[1]);
}
