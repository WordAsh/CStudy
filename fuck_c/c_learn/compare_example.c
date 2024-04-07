#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>


//·ºÐÍ±à³Ì

int compare(const void* a, const void* b);

void generic_sort(void* array, size_t element_size, size_t element_count, int(*compare)(const void*, const void*));

int main_compare(void)
{
	int ints[] = { -2,99,45,23,-145 };
	size_t ints_cnt = sizeof(ints) / sizeof(ints[0]);

	int num1 = 1;
	int num2 = 2;

	printf("%d\n", compare(&num1, &num2));

	generic_sort(ints, sizeof(ints[0]), ints_cnt, compare);

	for (size_t i = 0; i < ints_cnt; i++)
	{
		printf("%d ", ints[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}

int compare(const void* a, const void* b) {
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	if (arg1 < arg2) return -1;
	if (arg1 > arg2) return 1;
	return 0;
}

void generic_sort(void* array, size_t element_size, size_t element_count, int(*compare)(const void*, const void*)) {
	qsort(array, element_count, element_size, compare);
}