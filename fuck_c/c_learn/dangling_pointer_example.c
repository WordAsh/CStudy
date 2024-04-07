#include <stdio.h>
#include <stdlib.h>

int main_dangling_pointer(void)
{
	int* ptr = (int*)malloc(sizeof(int));

	if (ptr == NULL) {
		printf("Memory allocation failed\n");
		return EXIT_FAILURE;
	}

	*ptr = 10;
	printf("Value at ptr: %d\n",*ptr);

	free(ptr);

	//此时ptr成为悬挂指针
	//如果此时再访问悬挂指针，非常危险，不应该在实际编程中使用
	
	//printf("Value at ptr: %d\n", *ptr);
	
	//将ptr设置为NULL，避免悬挂指针
	ptr = NULL;

	return EXIT_SUCCESS;
}