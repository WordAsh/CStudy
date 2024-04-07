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

	//��ʱptr��Ϊ����ָ��
	//�����ʱ�ٷ�������ָ�룬�ǳ�Σ�գ���Ӧ����ʵ�ʱ����ʹ��
	
	//printf("Value at ptr: %d\n", *ptr);
	
	//��ptr����ΪNULL����������ָ��
	ptr = NULL;

	return EXIT_SUCCESS;
}