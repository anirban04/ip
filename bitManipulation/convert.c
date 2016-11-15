#include <stdio.h>
#include <stdlib.h>

int convert(int a, int b) {
  	int cnt = 0;
	while(a != b) {
	  	if ((a & 0x1) != (b & 0x1))
			cnt++;
		a = a >> 1;
		b = b >> 1;
	}
	return cnt;
}

int main() {
	printf("%d\n", convert(29, 15));
}
