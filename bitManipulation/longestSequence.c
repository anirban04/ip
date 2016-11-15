#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int* getAltArr(int num) {
	int* arr = malloc(32 * sizeof(int));
	memset(arr, 0, 32 * sizeof(int));
	int arrIdx = 0;
	int oneCnt = 0;
	int zeroCnt = 0;

	for (int i = 0; i < 32; i++) {
		if ((0x1 & num) == 1) {
			if (zeroCnt != 0) {
				arr[arrIdx] = -1 * zeroCnt;
				arrIdx++;
				zeroCnt = 0;
			}
			oneCnt++;
		}
		else {
			if (oneCnt != 0) {
				arr[arrIdx] = oneCnt;
				arrIdx++;
				oneCnt = 0;
			}
			zeroCnt++;
		
		}
		num = num >> 0x1;
	}
	return arr;
}

int getLonSeqOnes(int* arr) {
  	int maxLen = 0;
	for (int i = 0; i < 32; i++) {
		if (arr[i] == -1) {
			int left = 0;
			int right = 0;
			if ((i - 1) >= 0)
				left = arr[i - 1];
			if ((i + 1) < 32)
				right = arr[i + 1];
			if (maxLen < (left + right))
				maxLen = left + right;
		}
	}
	return maxLen + 1;
}

int findLonSeq(int num) {
	int* arr = getAltArr(num);
	return getLonSeqOnes(arr);
}

int main() {
	printf("%d\n", findLonSeq(1775));
}
