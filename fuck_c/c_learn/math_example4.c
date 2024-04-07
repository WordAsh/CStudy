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

int main_math4()
{
	double value = 2.845;
	double divisor = 2.0;

	//���뺯��
	printf("round(%f) = %f\n",value,round(value));
	printf("lround(%f) = %ld\n", value, lround(value));
	printf("llround(%f) = %lld\n", value, llround(value));
	printf("rint(%f) = %f\n", value, rint(value));
	printf("lrint(%f) = %ld\n", value, lrint(value));
	printf("llrint(%f) = %lld\n", value, llrint(value));
	printf("nearbyint(%f) = %f\n", value, nearbyint(value));

	//ʣ�ຯ��
	printf("remainder(%f, %f) = %f\n", value, divisor, remainder(value, divisor));

	//�������,չʾ��ͬ��������ԶԱ�
	double special_value = 2.5;
	printf("\nSpecial Case(%f):\n", special_value);
	printf("round(%f) = %f\n", special_value, round(special_value));
	printf("rint(%f) = %f\n", special_value, rint(special_value));
	printf("nearbyint(%f) = %f\n", special_value, nearbyint(special_value));

	return 0;
}