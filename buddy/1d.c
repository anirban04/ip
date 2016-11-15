#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int* bitmap;
static int numLevels;
static int bitMapSz;

int getNumLevels(int size) {
	int temp = 0x1;
	int levelCnt = 1;

	while(temp < size) {
		temp = temp << 1;
		levelCnt++;
	}
	return levelCnt;
}

int getBitmapSize(int numLevels, int size) {
	int bitmapSize = pow(2, numLevels - 1) - 1;
	bitmapSize += size;
	return bitmapSize;
}

void setBitsFin(int start, int end) {
  	int maxLevel = numLevels  - 1;
	int finStart = pow(2, maxLevel) - 1;
	int setStart = start + finStart;
	int setEnd = end + finStart;
	for (int i = setStart; i <= setEnd; i++) {
		bitmap[i] = 1;
	}
}

void setLevel(int level, int start, int end) {
	int lStart = pow(2, level) - 1;
	int setStart = lStart + start;
	int setEnd = lStart + end;
	for(int i = setStart; i <= setEnd; i++) {
		int left = 1;
		int right = 1;
		if (((2 * i) + 1) < bitMapSz)
			left = bitmap[(2 * i) + 1];
		if (((2 * i) + 2) < bitMapSz)
			right = bitmap[(2 * i) + 2];

		if (left == 1 && right == 1)
			bitmap[i] = 1;
	}
}

void setBits(int start, int len) {
	int end = start + len - 1;
	setBitsFin(start, end);
	for (int i = numLevels - 2; i >= 0; i--) {
	  	start = start / 2;
		end = end / 2;
		setLevel(i, start, end);
	}
}

void init(int* map, int size) {
	bitmap = map;
	numLevels = getNumLevels(size);
	printf("Numlevels = %d\n", numLevels);
	bitMapSz = getBitmapSize(numLevels, size);
	printf("bitMapSz = %d\n", bitMapSz);
}

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[15];
	memset(arr, 0, 15 * sizeof(int));
	init(arr, 8);
	printArr(arr, 15);
	setBits(1, 4);
	printArr(arr, 15);
	setBits(0, 1);
	printArr(arr, 15);
	setBits(5, 3);
	printArr(arr, 15);

}
