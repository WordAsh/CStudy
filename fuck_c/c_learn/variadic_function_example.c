#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


/*
*����ƽ����
* @param num_args ����������
* @param ... �ɱ�������б���Ҫ�����ƽ��������
* @return ƽ����
*/
double average(int num_args, ...);

int main_variadic(void)
{
	printf("Avg 2,3,4,5 = %f\n", average(4, 2, 3, 4, 5));
	//��־��¼
	//snprintf

	return EXIT_SUCCESS;
}

double average(int num_args, ...) {
	double sum = 0.0;
	va_list args;

	va_start(args, num_args);

	for (size_t i = 0; i < num_args; i++)
	{
		sum += va_arg(args, int);	//va_arg��ȡ��һ������
	}

	va_end(args);

	return num_args > 0 ? sum / num_args : 0;
}