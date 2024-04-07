#pragma once

#include <stddef.h>

//context Ϊ�ܹ�ʦԤ��

typedef int (*CompareFunc)(const void* a, const void* b, void* context);

void genericSort(void* array, size_t length, size_t size, CompareFunc compare, void* context);
