#pragma once

#include <stddef.h>

//context Îª¼Ü¹¹Ê¦Ô¤Áô

typedef int (*CompareFunc)(const void* a, const void* b, void* context);

void genericSort(void* array, size_t length, size_t size, CompareFunc compare, void* context);
