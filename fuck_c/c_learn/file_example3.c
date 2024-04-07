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
		perror("�޷����ļ�");
		return EXIT_FAILURE;
	}

	//ftell
	//fseek
	//rewind

	//ʹ��ftell��ȡ��ǰ�ļ�ָ���λ��
	long position = ftell(file_ptr);
	printf("��ǰλ�ã� %ld\n",position);
	
	char buffer[100];
	if (fgets(buffer,sizeof(buffer),file_ptr) != NULL) {
		printf("���ļ���ȡ: %s",buffer);
		//�ٴ�ʹ��ftell��ȡ�µ�λ��
		position = ftell(file_ptr);
		printf("��ȡ�����λ��: %ld\n",position);
	}

	//ʹ��fseek�����ƶ����ļ��Ŀ�ʼ
	fseek(file_ptr, 0, SEEK_SET);
	printf("ʹ��fseek���ƶ�����ʼ��λ�ã�SEEK_SET = 0 : %ld\n",ftell(file_ptr));

	//rewind
	rewind(file_ptr);
	printf("ʹ��rewindֱ���ƶ����ļ���ʼ��λ��: %ld\n", ftell(file_ptr));

	fclose(file_ptr);

	return 0;
}