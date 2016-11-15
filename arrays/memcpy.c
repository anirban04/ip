#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBuf(char* buf, int len) {
	for (int i = 0; i < len; i++)
		printf("%c ", buf[i]);
	printf("\n");
}

void myMemcpy(void* dst, void* src, int len) {
	if (dst == NULL || src == NULL || len == 0 || dst == src)
		return;

	char* pDst = (char*)dst;
	char* pSrc = (char*)src;

	if (pSrc < pDst && pSrc + len > pDst)
		for (int i = len - 1; i >= 0; i--)
			pDst[i] = pSrc[i];
	else
		for (int i = 0; i < len; i++)
			pDst[i] =pSrc[i];
}

int main() {
	char arr[20] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'};
	int len = 8;
	char* dst = &arr[5];
	char* src = &arr[6];
	printBuf(src, len);
	printBuf(dst, len);
	printf("\n");
	myMemcpy(dst, src, len);
	printBuf(dst, len);
}
