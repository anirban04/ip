#include<stdio.h>
#include<stdlib.h>

int swapEvenOdd(unsigned int num) {
	return (((num & 0xAAAAAAAA) >> 1) | (num & 0x55555555) << 1);
}

int main() {
	printf("0x%x \n", swapEvenOdd(0xCA));
}
