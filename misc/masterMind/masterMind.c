#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int getIdx(char c) {
	switch (c) {
		case 'R':
			return 0;
			break;
		case 'G':
			return 1;
			break;
		case 'B':
			return 2;
			break;
		case 'Y':
			return 3;
			break;
	}
	return -1;
}

int* getPoints(char* soln, char* guess) {
	int freqTable[4] = {0, 0, 0, 0};
	int *res = malloc(2 * sizeof(int));
	memset(res, 0, 2 * sizeof(int));
	for (int i = 0; i < 4; i++) {
		if(soln[i] == guess[i])
			res[0]++;
		else {
			freqTable[getIdx(soln[i])]++;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (freqTable[getIdx(guess[i])] > 0) {
			freqTable[getIdx(guess[i])]--;
			res[1]++;
		}
	}
	return res;
}

int main(int argc, char** argv) {
  	int *res = getPoints(argv[1], argv[2]);
	printf("%d, %d\n", res[0], res[1]);
}
