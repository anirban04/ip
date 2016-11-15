#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char * str, int i, int j) {
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

int getNext(char* str, int i) {
	int len = strlen(str);
	while(i <= len) {
		if (str[i] != ' ') {
			return i;
		}
		i++;  
	}
	return -1;
}

void removeSpaces(char* str) {
	int len = strlen(str);
	int i = 0;
	int j = 0;
	while(j < len) {
		if (str[i] == ' ') {
		  	int swapIdx = getNext(str, j);
			swap(str, i, swapIdx);
			i++;
			j = swapIdx + 1;
		}
		else {
			i++;
			j++;
		}
	}
}

int main() {
  	char arr[100] = "          a    scn alsknlsC ;qoscnQOIC ;oscnqOICNqow coqWo'iqwmc   ";
	printf("%s\n", arr);
	removeSpaces(arr);
	printf("%s\n", arr);
	return 0;
}
