#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>


void print_budgets(double* budgets, int size);

int main_malloc1(void)
{
	//��̬��������Ԥ���б�
	int size = 3;	//��ʼ��Ԥ������

	double* budgets = (double*)malloc(size * sizeof(double));
	if (budgets == NULL) {
		perror("Failed to allocate initial budgets.");
		return EXIT_FAILURE;
	}

	//����ĳ�ʼԤ�����
	budgets[0] = 10000;
	budgets[1] = 12000;
	budgets[2] = 15000;

	print_budgets(budgets, size);

	//�µ�һ�꣬��Ҫ����Ԥ����
	int new_size = 5;
	double* new_budgets = (double*)realloc(budgets, new_size * sizeof(double));



	if (new_budgets == NULL) {
		perror("Failed to realloc budgets.");
		free(budgets);
		return EXIT_FAILURE;
	}

	budgets = new_budgets;	//����ָ��
	budgets[3] = 20000;
	budgets[4] = 24000;

	print_budgets(budgets, new_size);
	free(budgets);

	return EXIT_SUCCESS;
}

void print_budgets(double* budgets, int size) {
	printf("Current budgets:\n");
	for (size_t i = 0; i < size;i++) {
		printf("Department [%zd]: $%.2f\n", i + 1, budgets[i]);
	}
}