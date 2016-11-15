#include <stdio.h>
#include <stdlib.h>


printMatrix(int* matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%d ", matrix[i * size + j]);
		printf("\n");
	}
	printf("\n");
}

void transpose(int* matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
			  	int *a = matrix + ((i * n) + j);
				int *b = matrix + ((j * n) + i);
				int temp = *a;
				*a = *b;
				*b = temp;
			}

		}
	}
}

void swapCol(int* matrix, int n) {
	int left = 0;
	int right = n - 1;

	while(left < right) {
		for (int i = 0; i < n; i++) {
			int *arr = matrix + (i * n);
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

		}
		left++;
		right--;
	}
}

void swapRow(int* matrix, int n) {
	int top = 0;
	int bottom = n - 1;

	while(top < bottom) {
	  	int *i1 = matrix + (top * n);
	  	int *i2 = matrix + (bottom * n);
		for (int j = 0; j < n; j++) {
			int temp = *(i1 + j);
			*(i1 + j) = *(i2 + j);
			*(i2 + j) = temp;
		}
	  	top++;
		bottom--;
	}
}

void rotateClockWise(int* matrix, int n) {
  	printf("rotating clockwise\n");
	transpose(matrix, n);
	swapCol(matrix, n);
}

void rotateAntiClockWise(int* matrix, int n) {
  	printf("rotating AntiClockwise\n");
	transpose(matrix, n);
	swapRow(matrix, n);
}

int main() {
	int matrix[3][3] = {{1, 2, 3},
			    {4, 5, 6},
			    {7, 8, 9}};

	printMatrix((int *)matrix, 3);
	//transpose(matrix, 3);
	//printMatrix((int *)matrix, 3);
	//rotateClockWise((int*)matrix, 3);
	//printMatrix((int *)matrix, 3);
	rotateAntiClockWise((int*)matrix, 3);
	printMatrix((int *)matrix, 3);
}
