#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMaxRepeatCount(char* str) {
	int i = 1;
	int count = 1;
	int len = strlen(str);
	while(i < len) {
		if (str[i] == str[i - 1])
			count++;
		else
		  	count = 1;
		i++;
	}
	return count;
}

char* compress(char* str) {
	if(getMaxRepeatCount(str) < 3)
		return str;
	int len = strlen(str);
	char* res = malloc(len);
	int count = 1;
	int i = 1;

	int resIdx = 0;
	while(i < len) {
		if (str[i] == str[i - 1])
			count++;
		else {
			res[resIdx] = str[i - 1];
			resIdx++;
			res[resIdx] = (char)(count + '0');
			resIdx++;
			count = 1;
		}
		i++;
	}
	res[resIdx] = str[i - 1];
	resIdx++;
	res[resIdx] = (char)(count + '0');
	resIdx++;
	res[resIdx] = '\0';
	return res;
}

int main() {
	char* str = "aabbccaa";
	printf("Original String  = %s\nCompressed String = %s\n", str, compress(str));
}
