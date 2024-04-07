#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>

int main_file3(void)
{
	FILE* file_ptr;

	errno_t err = fopen_s(&file_ptr, "C:\\Users\\Rigon\\Desktop\\test.txt", "r+");

	if (err != 0 || file_ptr == NULL) {
		perror("无法打开文件");
		return EXIT_FAILURE;
	}

	//ftell
	//fseek
	//rewind

	//使用ftell获取当前文件指针的位置
	long position = ftell(file_ptr);
	printf("当前位置： %ld\n",position);
	
	char buffer[100];
	if (fgets(buffer,sizeof(buffer),file_ptr) != NULL) {
		printf("从文件读取: %s",buffer);
		//再次使用ftell获取新的位置
		position = ftell(file_ptr);
		printf("读取后的新位置: %ld\n",position);
	}

	//使用fseek函数移动到文件的开始
	fseek(file_ptr, 0, SEEK_SET);
	printf("使用fseek后移动到开始的位置，SEEK_SET = 0 : %ld\n",ftell(file_ptr));

	//rewind
	rewind(file_ptr);
	printf("使用rewind直接移动到文件开始的位置: %ld\n", ftell(file_ptr));

	fclose(file_ptr);

	return 0;
}