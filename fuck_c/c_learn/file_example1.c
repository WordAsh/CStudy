#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>

int main_file1(void)
{
	FILE* file_stream = NULL;

	char buffer[256];

	//打开文件，设定文件路径要读取的文件 设定文件的操作模式r
	errno_t err = fopen_s(&file_stream, "C:\\Users\\Rigon\\Desktop\\test.txt", "r");

	//文件路径不对，文件不存在，文件出现了异常，文件没有权限访问...
	//read
	// != NULL

	if (err != 0 || file_stream == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	while (fgets(buffer,sizeof(buffer),file_stream) != NULL) {
		printf("%s",buffer);
	}
	
	//此时file_stream指针已经把所有的文件内容读完了，循环读完了，指针指向最后一个位置了，所以再往下读....啥也没有

	memset(buffer, 0, sizeof(buffer));

	printf("\n");
	rewind(file_stream);

	int ch;

	while ((ch = fgetc(file_stream)) != EOF) {
		putchar(ch);
	}

	if (fclose(file_stream) != 0) {
		perror("Error closing file");
		return EXIT_FAILURE;
	}

	return 0;
}