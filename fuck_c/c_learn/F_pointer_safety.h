#pragma once

#include <stdbool.h>

bool is_nullptr(const void* ptr);

/*
* 安全地解引用指针
* 如果指针为NULL，记录错误并且返回指定的默认值
* @param ptr 待解引用的指针
* @param defaultValue 解引用失败时的默认值
* @return 指针指向的值，如果指针为NULL，则为defaulValue
*/
#define SAFE_DEREF(ptr,defaultValue) \ (is_nullptr(ptr) ? (log_error("Attempted to deference a NULL pointer."),defaultValue): *(ptr));