#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

typedef void(*Callback)(int);

void traverse(int* array, int size, Callback function);
void print_element(int element);
void double_element(int element);
void is_even(int element);

int main_callback(void)
{
	int numbers[] = {1,2,3,4,5};
	int size = sizeof(numbers) / sizeof(int);

	traverse(numbers, size, print_element);
	traverse(numbers, size, double_element);
	traverse(numbers, size, is_even);

	return EXIT_SUCCESS;
}

void traverse(int* array, int size, Callback function) {
	for (size_t i = 0; i < size; i++)
	{
		function(array[i]);
	}
}

void print_element(int element) {
	printf("%d\n", element);
}

void double_element(int element) {
	printf("Double %d is %d\n", element, element * 2);
}

void is_even(int element) {
	if (element % 2 == 0) {
		printf("%d is even.\n", element);
	}
	else {
		printf("%d is odd.\n", element);
	}
}