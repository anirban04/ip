#include <stdio.h>
#include <stdlib.h>

void* alignedMalloc(int size, int alignment) {
  	char* mainPtr = malloc(size + alignment - 1 + sizeof(void*));
	printf("%p\n", mainPtr);
	char* retPtr = mainPtr + sizeof(void*);
	while(((unsigned int)retPtr) % alignment) {
		retPtr++;
	}
	char* savePtr = retPtr - sizeof(void*);
	*((size_t*)savePtr) = (size_t)mainPtr;
	return (void*)retPtr;
}

void alignedFree(void* ptr) {
  	char* savePtr = ptr;
	savePtr = savePtr - sizeof(void*);
	void* freePtr = *((size_t*)savePtr);
	printf("%p\n", freePtr);
	free(freePtr);
}

int main() {
  	int i = 0;
  	while(i++ < 5) {
		int* ptr = (int*)alignedMalloc(1024, 32);
		printf("Got pointer with address %p\n", ptr);
		alignedFree(ptr);
	}
}
