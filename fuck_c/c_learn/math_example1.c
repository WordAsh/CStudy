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


int main_math1(void)
{
	double number = 0.0;
	double result = 0.0;

	puts("������һ�������Լ�����ƽ����:");
	scanf("%lf",&number);

	errno = 0;
	result = sqrt(number);

	//EDOM ���������
	if (errno == EDOM) {
		puts("����:����ֵΪ�������޷�������ƽ����!");
	}
	else if(errno == ERANGE){
		puts("����:���������Χ!");
	}
	else if (errno == HUGE_VAL) {
		puts("����:���������Χ!���� HUGE_VAL!");
	}
	else {
		printf("���� %.2f ��ƽ����Ϊ: %.2f\n", number, result);
	}

	return 0;
}