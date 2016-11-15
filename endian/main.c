#include<stdio.h>
#include<stdlib.h>

int isLittleEndian() {
	int a = 0x11223344;
	char* test = &a;
	if (0x44 == (*test))
		return 1;
	return 0;
}

int main() {
	printf("%d\n", isLittleEndian());
}
