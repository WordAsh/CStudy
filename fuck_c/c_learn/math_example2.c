#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS	//����ʹ��C�����еķǰ�ȫ�ĺ��������Ծ���
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
	//��̬���� -> ����ԭ��

	double numbers[] = { 0.0,1.0,-1.0,HUGE_VAL,-HUGE_VAL,NAN,DBL_MIN / 2.0 };
	
	int size = sizeof(numbers) / sizeof(numbers[0]);

	for (size_t i = 0; i < size;i++) {
		check_float(numbers[i]);
	}

	return 0;
}

void check_float(double number) {
	//��鸡�����ķ���
	switch (_fpclassf(number))
	{
	case FP_INFINITE: printf("%.2f �������\n", number); break;
	case FP_NAN: printf("%.2f ����һ������(NaN)\n", number); break;
	case FP_NORMAL: printf("%.2f ��һ��������\n", number); break;
	case FP_SUBNORMAL: printf("%.2f ��һ����������\n", number); break;
	case FP_ZERO: printf("%.2f ����\n", number); break;
	}

	if (isfinite(number))	printf("%.2f �����޵�.\n",number);
	if (isinf(number))	printf("%.2f �����޵�.\n", number);
	if (isnan(number))	printf("%.2f ��NaN.\n", number);
	if (isnormal(number))	printf("%.2f ��������.\n", number);
	if (signbit(number))	printf("%.2f �����޵�.\n", number);
	else                    printf("%.2f �ķ���λ��������\n",number);

	printf("\n");
}