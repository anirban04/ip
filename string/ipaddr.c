#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int convert (char* arr, int low, int high) {
	int res = 0;
  	while(low <= high) {
		res = (10 *  res) + (int)(arr[low] - '0');
		low++;
	}
	return res;
}

int* convertIp (char* str) {
	int len = strlen(str);
	if (len > 15)
		return NULL;

	int dotCnt = 0;
	int resIdx = 0;
	int l = 0;
	int r = 0;
	int *res = malloc(4 * sizeof(int));

	while(r < len) {
		if (str[r] != '.' && !(str[r] >= '0' && str[r] <= '9')) {
			free(res);
			return NULL;
		}

		if (str[r] == '.') {
			dotCnt++;
			if ((l == r) || (r - l > 3) || (dotCnt > 3)) {
				free(res);
				return NULL;
			}
			else {
				res[resIdx] = convert(str, l, r - 1);
				if (res[resIdx] > 255) {
					free(res);
					return NULL;
				}
				resIdx++;
			}
			l = r + 1;
			if (l >= len) {
				free(res);
				return NULL;
			}
		}
		r++;
	}
	if ((l == r) || (r - l > 3)) {
		free(res);
		return NULL;
	}
	else {
		res[resIdx] = convert(str, l, r - 1);
		if (res[resIdx] > 255) {
			free(res);
			return NULL;
		}
	}
	return res;
}

int main (int argc, char** argv) {
	char* str = argv[1];
	int* res = convertIp(str);
	if (res == NULL)
		printf("Invalid input\n");
	else {
		for (int i = 0; i < 4; i++)
			printf("%d ", res[i]);
		printf("\n");
	}
}
