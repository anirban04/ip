#include <stdio.h>
#include <stdlib.h>

char* convert(double num) {
	char* res = malloc(34 * sizeof(char));
	int idx = 0;
	res[idx] = '.';
	idx++;
	while(idx < 34 && num > 0) {
		num = num * 2;
		if (num >= 1) {
			res[idx] = (1 + '0');
			num = num - 1;
			idx++;
		}
		else {
			res[idx] = (0 + '0');
			idx++;
		}
	}
	if (idx == 34)
		return "ERROR";
	else {
		res[idx] = '\0';
		return res;
	}
}

int main() {
	printf("%s\n", convert(.25));
}
