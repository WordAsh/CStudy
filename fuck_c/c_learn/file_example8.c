#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>

int main_file8(void)
{
	FILE* source_file, * target_file;

	char* source_path = "C:\\Users\\Rigon\\Desktop\\frank.txt";
	char* target_path = "C:\\Users\\Rigon\\Desktop\\fuck.txt";

	char buffer[1024];

	size_t bytes_read;

	errno_t err = fopen_s(&source_file, source_path, "rb");

	if (err != 0 || source_file == NULL) {
		perror("无法打开源文件");
		return EXIT_FAILURE;
	}

	err = fopen_s(&target_file, target_path, "wb");

	if (err != 0 || target_file == NULL) {
		perror("无法打开目标文件");
		return EXIT_FAILURE;
	}

	while((bytes_read = fread(buffer,1,sizeof(buffer),source_file)) > 0){
		fwrite(buffer, 1, bytes_read, target_file);
	}

	_fcloseall();

	puts("文件复制完成!");

	return 0;
}