#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>


void print_budgets(double* budgets, int size);

int main_malloc1(void)
{
	//动态调整部门预算列表
	int size = 3;	//初始的预算项数

	double* budgets = (double*)malloc(size * sizeof(double));
	if (budgets == NULL) {
		perror("Failed to allocate initial budgets.");
		return EXIT_FAILURE;
	}

	//假设的初始预算分配
	budgets[0] = 10000;
	budgets[1] = 12000;
	budgets[2] = 15000;

	print_budgets(budgets, size);

	//新的一年，需要增加预算项
	int new_size = 5;
	double* new_budgets = (double*)realloc(budgets, new_size * sizeof(double));



	if (new_budgets == NULL) {
		perror("Failed to realloc budgets.");
		free(budgets);
		return EXIT_FAILURE;
	}

	budgets = new_budgets;	//更新指针
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