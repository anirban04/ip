#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a>=b)?a:b)

void add(char* s1, char* s2, char** result) {
  	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int idx1 = len1 - 1;
	int idx2 = len2 - 1;
	int carry = 0;
	int maxLen = MAX(len1, len2);
	char* res;
	res = malloc(maxLen + 1);
	int resIdx = maxLen;
	res[resIdx] = '\0';
	resIdx--;

	while(idx1 >=0 || idx2 >=0) {
		while(idx1 >= 0 && idx2 >= 0) {
			int temp = (s1[idx1] - '0') + (s2[idx2] - '0') + carry;
			res[resIdx] = (temp % 10) + '0';
			carry = temp / 10;
			resIdx--;
			idx1--;
			idx2--;
		}
		while(idx1 >= 0) {
			int temp = (s1[idx1] - '0') + carry;
			res[resIdx] = (temp % 10) + '0';
			carry = temp / 10;
			resIdx--;
			idx1--;
		}
		while(idx2 >= 0) {
			int temp = (s2[idx2] - '0') + carry;
			res[resIdx] = (temp % 10) + '0';
			carry = temp / 10;
			resIdx--;
			idx2--;
		}
	}

	if (carry > 0) {
		char* temp = malloc(maxLen + 2);
		temp[0] = carry + '0';
		for (int i = 0; i <= maxLen; i++) 
			temp[i + 1] = res[i];
		free(res);
		res = temp;
	}
	*result = res;
}

void multiply(char* s1, char* s2, char** result) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	char* sSh;
	char* sLn;

	if (len1 <= len2) {
		sSh = s1;
		sLn = s2;
	}
	else {
		sSh = s2;
		sLn = s1;
	}
	int numRows = strlen(sSh);
	int numCols = strlen(sLn);
	char** strLst = malloc(sizeof(char*) * numRows);
	for (int i = 0; i < numRows; i++) {
		strLst[i] = malloc(numCols + 1 + i);
		memset(strLst[i], '0', numCols + 1 + i);
		strLst[i][numCols + i] = '\0';
	}
	
	int shLen = numRows;
	int lnLen = numCols;
	int idx = 0;
	for (int i = shLen - 1; i >= 0; i--) {
		int carry = 0;
		for (int j = lnLen - 1; j >= 0; j--) {
		  	int a = sSh[i] - '0';
			int b = sLn[j] - '0';
			int temp = (a * b) + carry;
			carry = temp /10;
			temp = temp % 10;
			strLst[idx][j] = temp + '0';		
		}
		if (carry > 0) {
			char* bigBuf = malloc(strlen(strLst[idx]) + 2);
			bigBuf[0] = carry + '0';
			for(int i = 0; i <= strlen(strLst[idx]); i++) {
				bigBuf[i + 1] = strLst[idx][i];
			}
			char* temp = strLst[idx];
			strLst[idx] = bigBuf;
			free(temp);
		}
		idx++;
	}
	char* temp = "0";
	char* res;
	for (int i = 0; i < numRows; i++) {
	  	add(temp, strLst[i], &res);
		temp = res;
		free(strLst[i]);
	}
	*result = res;
}

int main(int argc, char** argv) {
  	char* res;
	int resSize;
	add(argv[1], argv[2], &res);
	printf("Add result = %s\n", res);
	free(res);
	multiply(argv[1], argv[2], &res);
	printf("Multiply result = %s\n", res);
	free(res);
}
