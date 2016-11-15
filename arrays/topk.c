#include <stdio.h>
#include <stdlib.h>

#define KSIZE 4 

int* topList;
int listSize; 

printTopK(int* arr, int size) {
  	printf("[");
	for(int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
  	printf("]\n");
}

int swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int* arr, int low, int high) {
	int i = low + 1;
	int j = high;
	int pivot = arr[low];
	while(i <= j) {
		while((i <= j) && (arr[i] > pivot))
			i++;
		while((i <= j) && (arr[j] < pivot))
			j--;
		if (i < j) {
		  	swap(arr, i, j);
			i++;
			j--;
		}
	}
	swap(arr, i - 1, low);
	return (i - 1);
}

void _sort(int* arr, int low, int high) {
  	if (low >= high)
		return;
	int pivotPos = low;
	int partPos = partition(arr, low, high);
	_sort(arr, low, partPos - 1);
	_sort(arr, partPos + 1, high);
}
void sort(int* arr, int listSize) {
	_sort(arr, 0, listSize - 1);
}

int findPos(int* arr, int arrSize, int a) {
  	if (a < arr[arrSize - 1])
		return -1;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] < a)
			return i;
	}
	return -1;
}

void insertArr(int* arr, int arrSize, int pos, int a) {
  	int i = arrSize - 1;
	int j = arrSize - 2;
	while(i > pos) {
		arr[i] = arr[j];
		i--;
		j--;
	}
	arr[pos] = a;
}

void insert(int a) {
  static int numEle = 0;
  int pos;

  if (numEle == 0) {
  	topList = malloc(listSize * sizeof(int));
  }

  if (numEle < listSize) {
  	topList[numEle] = a;
  }
  else {
  	pos = findPos(topList, listSize, a);
	if (pos ==  -1)
		return;
	else
		insertArr(topList, listSize, pos, a);
  }

  numEle++;
  if (numEle == listSize) {
  	sort(topList, listSize);
  }
}

int* getTopK(void) {
	return topList;
}

void initTopK(int size) {
	listSize = size;
}

int main() {
  	int num;
  	initTopK(KSIZE);
	for (int i = 0; i < 20; i++) {
	  	num = rand() % 10;
		printf("Inserting %d\n", num);
		insert(num);
	}
	
	printTopK(getTopK(), KSIZE);
}
