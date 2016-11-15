#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int sign(int a) {
	a = a >> 31;
	return !a;
}

int getMax(int a, int b) {
	int c = a - b;

	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);

	int useSignA = sa ^ sb;
	int useSignC = !useSignA;

	int x = (sa * useSignA) + (sc * useSignC);
	int y = !x;

	return x * a + y * b;
}

int main(int argc, char** argv) {
  	if (argc < 3)
		return 0;
	printf("Max is %d\n", getMax(atoi(argv[1]), atoi(argv[2])));
}
