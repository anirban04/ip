#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void sort(int* arr, int len) {

}

void printAllPairs(int* arr, int size, int sum) {
	sort(arr, size);
	int low = 0;
	int high = size - 1;
	while(low < high) {
	  	int curSum = arr[low] + arr[high];
		if (curSum == sum) {
			printf("%d:%d\n", arr[low], arr[high]);
			low++;
			while(low < high && arr[low - 1] == arr[low])
				low++;
		}
		else if(curSum < sum) {
			low++;
			while(low < high && arr[low - 1] == arr[low])
				low++;
		}
		else {
		  	high--;
			while(high > low && arr[high + 1] == arr[high])
		  		high--;
		}
	}
}

int main() {
  	int arr[9] = {0, 0, 2, 2, 5, 5, 7, 7, 8};
	printAllPairs(arr, 9, 7);
}
