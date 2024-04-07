#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>


#define BUFFER_SIZE 1024

void read_file(const char* filename);
void append_log_safe(const char* logfile,const char* msg);
void clear_file(const char* file);
errno_t update_log_record_s(const char* log_file, const char* search_str, const char* replace_str);

int main_file6(void)
{
	const char* log_file = "C:\\Users\\Rigon\\Desktop\\test.log";
	const char* search_str = "456";
	const char* replace_str = "666";

	errno_t result = update_log_record_s(log_file, search_str, replace_str);

	if (result != 0) {
		char error_msg[256];
		strerror_s(error_msg, sizeof(error_msg), result);
		fprintf(stderr, "An error occurred: %s\n", error_msg);
	}
	else {
		printf("Record updated successfully.\n");
	}

	_fcloseall();

	return 0;
}


void read_file(const char* filename) {
	
	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, filename, "r");
	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "Failed to open config file for reading: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[100];
	while (fgets(buffer,sizeof(buffer),file_ptr) != NULL) {
		printf("%s",buffer);
	}

	fclose(file_ptr);
}

void append_log_safe(const char* logfile, const char* msg) {
	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, logfile, "a");
	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "Failed for log file to append: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	fprintf(file_ptr,"%s\n",msg);

	fclose(file_ptr);

}

void clear_file(const char* file) {
	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, file, "w");
	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "Failed for log file to append: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	//什么都不给，file会被清空

	fclose(file_ptr);
}

errno_t update_log_record_s(const char* filename, const char* search_str, const char* replace_str) {

	if (filename == NULL || search_str == NULL || replace_str == NULL) {
		return EINVAL;	//返回无效参数错误;
	}

	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, filename, "r+");
	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "Failed to open file for reading: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[BUFFER_SIZE];
	long position = 0;
	int found = 0;

	while (fgets(buffer,BUFFER_SIZE,file_ptr) != NULL) {
		if (strstr(buffer,search_str) != NULL) {
			found = 1;
			position = ftell(file_ptr) - (long)strlen(buffer);
			break;	//找到第一个匹配项后，立刻停止
		}
	}

	if (found) {
		fseek(file_ptr, position, SEEK_SET);		//移动回到找到记录的位置

		//计算替换文本与源文本的长度差异
		size_t replace_len = strlen(replace_str);
		size_t search_len = strlen(search_str);

		if (replace_len > BUFFER_SIZE - 1 || search_len > BUFFER_SIZE - 1) {
			fclose(file_ptr);

			return ERANGE;		//返回错误码，表示字符串长度超出范围
		}

		//写入新纪录之前，清除所在位置的行数据
		memset(buffer, " ", strlen(buffer) - 1);	//用空格填充，保持文件大小不变

		buffer[strlen(buffer) - 1] = '\n';			//保留换行符

		fseek(file_ptr, position, SEEK_SET);		//重新回到标记行的开始
		fputs(buffer, file_ptr);					//清除原来行的内容
		fseek(file_ptr, position, SEEK_SET);		//重新回到标记行的开始

		int result = fputs(replace_str, file_ptr);	//写入替换的字符串

		if (result == EOF) {
			fclose(file_ptr);
			return errno;
		}
	}
	else {
		fclose(file_ptr);
		return ENOENT;	//返回未找到的匹配项
	}
	fclose(file_ptr);
	return 0;
}