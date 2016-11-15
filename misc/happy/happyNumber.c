#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM 81

int getSum(int num) {
	int sum = 0;
	while(num > 0) {
		sum += pow((num % 10), 2);
		num = num / 10;
	}
	return sum;
}

int isHappy(int num) {
	int slow = getSum(num);
	int fast = getSum(getSum(num));
	while(fast != 1 && slow != fast) {
		slow = getSum(slow);
		fast = getSum(getSum(fast));
	}
	if (fast == 1)
	  	return 1;

	return 0;
}

int main() {
  	for (int i = 0; i < 82; i++) {
		sleep(1);
	  	printf("%d is %s\n", i, (isHappy(i) == 1) ? "Happy!": "Not Happy :(");
	}
}
