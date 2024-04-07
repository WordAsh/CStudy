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


int main_math1(void)
{
	double number = 0.0;
	double result = 0.0;

	puts("请输入一个数字以计算其平方根:");
	scanf("%lf",&number);

	errno = 0;
	result = sqrt(number);

	//EDOM 定义域错误
	if (errno == EDOM) {
		puts("错误:输入值为负数，无法计算其平方根!");
	}
	else if(errno == ERANGE){
		puts("错误:结果超出范围!");
	}
	else if (errno == HUGE_VAL) {
		puts("错误:结果超出范围!返回 HUGE_VAL!");
	}
	else {
		printf("数字 %.2f 的平方根为: %.2f\n", number, result);
	}

	return 0;
}