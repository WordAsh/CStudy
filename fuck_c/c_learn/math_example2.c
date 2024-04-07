#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS	//允许使用C语言中的非安全的函数，忽略警告
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <float.h>

void check_float(double number);

int main_math2(void)
{
	//静态分析 -> 编译原理

	double numbers[] = { 0.0,1.0,-1.0,HUGE_VAL,-HUGE_VAL,NAN,DBL_MIN / 2.0 };
	
	int size = sizeof(numbers) / sizeof(numbers[0]);

	for (size_t i = 0; i < size;i++) {
		check_float(numbers[i]);
	}

	return 0;
}

void check_float(double number) {
	//检查浮点数的分类
	switch (_fpclassf(number))
	{
	case FP_INFINITE: printf("%.2f 是无穷大\n", number); break;
	case FP_NAN: printf("%.2f 不是一个数字(NaN)\n", number); break;
	case FP_NORMAL: printf("%.2f 是一个正常数\n", number); break;
	case FP_SUBNORMAL: printf("%.2f 是一个次正常数\n", number); break;
	case FP_ZERO: printf("%.2f 是零\n", number); break;
	}

	if (isfinite(number))	printf("%.2f 是有限的.\n",number);
	if (isinf(number))	printf("%.2f 是无限的.\n", number);
	if (isnan(number))	printf("%.2f 是NaN.\n", number);
	if (isnormal(number))	printf("%.2f 是正常数.\n", number);
	if (signbit(number))	printf("%.2f 是有限的.\n", number);
	else                    printf("%.2f 的符号位是正或零\n",number);

	printf("\n");
}