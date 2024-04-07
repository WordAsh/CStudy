#include "S_sort.h"

#include <stdlib.h>

//跨平台的问题

//包装器
static int compareWrapper(void* context, const void* a, const void* b) {
	CompareFunc compare = (CompareFunc)context;
	return compare(a, b, NULL);		//Adjusted to match expected signature
}


void genericSort(void* array, size_t length, size_t size, CompareFunc compare, void* context) {
	//qsort_s
	//qsort()
	//qsort_r()
#ifdef _WIN32
	qsort_s(array, length, size, compareWrapper, (void*)compare);
#else
	qsort_r(array, length, size, compareWrapper, context);
#endif // _WIN32
}