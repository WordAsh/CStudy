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

	//���ļ����趨�ļ�·��Ҫ��ȡ���ļ� �趨�ļ��Ĳ���ģʽr
	errno_t err = fopen_s(&file_stream, "C:\\Users\\Rigon\\Desktop\\test.txt", "r");

	//�ļ�·�����ԣ��ļ������ڣ��ļ��������쳣���ļ�û��Ȩ�޷���...
	//read
	// != NULL

	if (err != 0 || file_stream == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	while (fgets(buffer,sizeof(buffer),file_stream) != NULL) {
		printf("%s",buffer);
	}
	
	//��ʱfile_streamָ���Ѿ������е��ļ����ݶ����ˣ�ѭ�������ˣ�ָ��ָ�����һ��λ���ˣ����������¶�....ɶҲû��

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