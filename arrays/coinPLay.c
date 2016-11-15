#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) (((a)>=(b))?(a):(b))
#define MIN(a, b) (((a)<=(b))?(a):(b))


int _getMaxProfit(int* arr, int low, int high) {
	if(low == high)
	  	return arr[low];
	if (low > high)
	  	return 0;
	int x = _getMaxProfit(arr, low + 1, high - 1);
	int y = _getMaxProfit(arr, low + 2, high);
	int z = _getMaxProfit(arr, low, high - 2);

	return (MAX(arr[low] + MIN(x, y), arr[high] + MIN(y, z)));
}

int getMaxProfit(int* arr, int len) {
	return _getMaxProfit(arr, 0, len - 1);
}

int main() {
	int arr[5] = {7, 2, 10, 9};
	printf("%d\n", getMaxProfit(arr, 5));
}
