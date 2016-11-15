#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[32];
int idx = 0;

void init() {
	memset(arr, 0, 32 * sizeof(int));
}


void addToHeap(int val) {
	
}

void heapify() {
	
}

void my_write(int val) {
	addToHeap(val);
	heapify();
}

void print() {

}

int main() {
  	init();
	my_write(7);
	my_write(6);
	my_write(5);
	my_write(4);
	print();
	my_write(3);
	my_write(2);
	my_write(1);
	my_write(9);
	print();
	my_write(8);
	print();
	my_write(7);
	my_write(6);
	my_write(5);
	my_write(4);
	print();
	my_write(3);
	my_write(2);
	my_write(1);
	my_write(12);
	print();
	my_write(13);
	my_write(54);
	my_write(34);
	print();
	my_write(43);
	my_write(63);
	my_write(73);
	my_write(74);
	print();
	my_write(73);
	my_write(75);
	my_write(76);
	print();
	my_write(77);
	my_write(77);
	my_write(78);
	print();
	my_write(79);
	my_write(80);
}
