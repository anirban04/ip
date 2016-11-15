#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2 

static int* arr;
static int size;

void init(int len) {
	size = 0;
	arr = malloc(len * sizeof(int));
	memset(arr, 0, len * sizeof(int));
}

void shiftRight(int idx) {
	int i = size - 1;
	int j = size;
	while(j >= idx) {
		arr[j] = arr[i];
		i--;
		j--;
	}
}

void add(int n) {
  	int added = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] >= n) {
			shiftRight(i);
			arr[i] = n;
			size++;
			return;
		}
	}
	arr[size] = n;
	size++;
}

void print() {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	init(SIZE);
	for (int i = 0; i < SIZE; i++) {
		add(rand() % 1000);
		print();
	}
}

