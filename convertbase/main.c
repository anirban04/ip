#include<stdio.h>
#include<stdlib.h>

int getNumHexDig(int n) {
	int cnt = 0;
	while(n > 0) {
		n = n / 16;
		cnt++;
	}
	return cnt;
}

char toHexDig(int n) {
	switch(n) {
	  	 case 0:
			return '0';
			break;
		 case 1:
			return '1';
			break;
		 case 2:
			return '2';
			break;
		 case 3:
			return '3';
			break;
		 case 4:
			return '4';
			break;
		 case 5:
			return '5';
			break;
		 case 6:
			return '6';
			break;
		 case 7:
			return '7';
			break;
		 case 8:
			return '8';
			break;
		 case 9:
			return '9';
			break;
		 case 10:
			return 'a';
			break;
		 case 11:
			return 'b';
			break;
		 case 12:
			return 'c';
			break;
		 case 13:
			return 'd';
			break;
		 case 14:
			return 'e';
			break;
		 case 15:
			return 'f';
			break;
		 default:
			return 'z';
	}
}

char* toHex(int n) {
	int len = getNumHexDig(n);
	char* buf = malloc(len + 3);
	int bufIdx = len + 3 - 1;
	buf[bufIdx] = '\0';
	bufIdx--;

	while(n > 0) {
		buf[bufIdx] = toHexDig(n % 16);
		n = n / 16;
		bufIdx--;
	}
	buf[bufIdx] = 'x';
	bufIdx--;
	buf[bufIdx] = '0';
	return buf;
}

int main() {
	printf("%s\n", toHex(4096));
}
