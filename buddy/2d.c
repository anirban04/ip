#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWSIZE (4)

static int numRows;

void printMatrix(int** matrix, int cols) {
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/*
void clearRow(int** matrix, int numRows, int rowIdx, int start, int end) {
	if (rowIdx < 0)
	  	return;

	if (rowIdx == numRows - 1) {
		for (int i = start; i <= end; i++)
		  	matrix[rowIdx][i] = 0;
	}
	else {
		for(int i = start; i <= end; i++) {
			if (matrix[rowIdx + 1][2 * i] == 0 &&
			    matrix[rowIdx + 1][(2 * i) + 1] == 0)
				matrix[rowIdx][i] = 0;
		}
	}
	clearRow(matrix, numRows, rowIdx - 1, start / 2, end / 2);
}

void clearBits(int** matrix, int numRows, int start, int length) {
	clearRow(matrix, numRows, numRows - 1, start, start + length - 1);
}
*/
void setRow(int** matrix, int rowIdx, int start, int end) {

	if (rowIdx == numRows - 1) {
		for (int i = start; i <= end; i++)
		  	matrix[rowIdx][i] = 1;
	}
	else {
		for(int i = start; i <= end; i++) {
			if (matrix[rowIdx + 1][2 * i] == 1 &&
			    matrix[rowIdx + 1][(2 * i) + 1] == 1)
				matrix[rowIdx][i] = 1;
		}
	}
}

void setBits(int** matrix, int start, int length) {

  	int rowIdx = numRows - 1;
	int end = start + length - 1;
	for (int i = rowIdx; i >= 0; i--) {
		setRow(matrix, i, start, end);
		start = start / 2;
		end = end / 2;
	}
}

int main() {
	int **matrix = malloc(sizeof(char*) * ROWSIZE);
	numRows = ROWSIZE;
	int numCols = pow(2, ROWSIZE - 1);
	int *mem = malloc(numCols * ROWSIZE * sizeof(int));
	memset(mem, 0, numCols * ROWSIZE * sizeof(int));
	for (int i = 0; i < ROWSIZE; i++) {
		matrix[i] = (mem + (i * numCols));
	}
	
	printMatrix(matrix, numCols);
	setBits(matrix, 1, 4);
	printMatrix(matrix, numCols);
	setBits(matrix, 0, 1);
	printMatrix(matrix, numCols);
	setBits(matrix, 5, 3);
	printMatrix(matrix, numCols);
}
