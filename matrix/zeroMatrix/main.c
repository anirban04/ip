#include <stdio.h>
#include <stdlib.h>

int** allocMatrix(int rows, int cols) {
	int** res = malloc(rows * sizeof(char*));
	int* buf = malloc(rows * cols * sizeof(int));
	for(int i = 0; i < rows; i++) {
		res[i] = buf + (cols * i); 
	}
	return res;
}

void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void populateMatrix(int** matrix, int rows, int cols) {
	int cnt = -1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = cnt++;
		}	
	}
}

void makeRowZero(int** matrix, int row, int cols) {
	for (int i = 0; i < cols; i++)
		matrix[row][i] = 0;
}

void makeColZero(int** matrix, int col, int rows) {
	for (int i = 0; i < rows; i++)
		matrix[i][col] = 0;
}

void zeroMatrix(int** matrix, int rows, int cols) {
	int rowZero = 0;
	int colZero = 0;

	if (matrix[0][0] == 0) {
		rowZero = 1;
		colZero = 1;
	} 	

	for (int i = 0; i < cols; i++) {
		if (matrix[0][i] == 0) {
			rowZero = 1;
		}
	}
	
	for (int i = 0; i < rows; i++) {
		if (matrix[i][0] == 0)
			colZero = 1;
	}

	for (int i = 1; i < rows; i++) {
		for (int j = 1; j < cols; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 0; i < cols; i++) {
		if (matrix[0][i] == 0)
			makeColZero(matrix, i, rows);
	}
	
	for (int i = 0; i < rows; i++) {
		if (matrix[i][0] == 0)
			makeRowZero(matrix, i, cols);
	}

	if (rowZero == 1)
		makeRowZero(matrix, 0, cols);
	if (colZero == 1)
		makeColZero(matrix, 0, rows);
}

int main() {
  	int rows = 4;
	int cols = 5;
	int** matrix = allocMatrix(rows, cols);
	populateMatrix(matrix, rows, cols);
	printMatrix(matrix, rows, cols);
	zeroMatrix(matrix, rows, cols);
	printMatrix(matrix, rows, cols);
}
