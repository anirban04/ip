#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void _toh(int num_disc, char source, char dest, char aux) {
  	if (num_disc == 0)
		return;

	_toh(num_disc - 1, source, aux, dest);
	printf("Move 1 disc from %c to %c using %c\n", source, dest, aux);
	_toh(num_disc - 1, aux, dest, source);
}

void _wildcard(char* s, char* arr, int idx) {
	if (idx == strlen(s)) {
		arr[idx] = '\0';
		printf("%s\n", arr);
		return;
	}
		
	if (s[idx] != '?') {
		arr[idx] = s[idx];
		_wildcard(s, arr, idx + 1);
	}
	else {
		arr[idx] = '1';
		_wildcard(s, arr, idx + 1);
		arr[idx] = '0';
		_wildcard(s, arr, idx + 1);
	}
}

void wildcard(char* s) {
  	char arr[strlen(s) + 1];
	_wildcard(s, arr, 0);
}

int main() {
	//_toh(3, 's', 'd', 'a');
  	wildcard("0?1?");
	return 0;
}
