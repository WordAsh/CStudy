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


int main_math3(void)
{
	double group1_max_tmp = 35.5;
	double group2_max_tmp = 37.8;

	double group1_min_tmp = -5.0;
	double group2_min_tmp = -3.8;

	double max_tmp = fmax(group1_max_tmp, group2_max_tmp);
	printf("max_tmp : %.2f\n", max_tmp);

	printf("min_tmp : %.2f\n", fmin(group1_min_tmp, group2_min_tmp));

	double temp_diff_max = fdim(group2_max_tmp, group1_max_tmp);
	printf("%.2f\n", temp_diff_max);

	double temp_diff_min = fdim(group1_min_tmp, group2_min_tmp);
	printf("%.2f\n", temp_diff_min);

	return 0;
}