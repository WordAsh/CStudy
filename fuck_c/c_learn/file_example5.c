#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>



int main_file5(void)
{
	FILE* stream;

	errno_t err = fopen_s(&stream, "C:\\Users\\Rigon\\Desktop\\123.txt", "w+");
	if(err != 0){
		printf_s("�ļ�д��ʧ��!\n");
		return EXIT_FAILURE;
	}

	int id = 230188;
	char* name = "Rigon";
	float temperature = 36.5;
	char grade = 'A';


	fprintf_s(stream, "Id: %d\n", id);
	fprintf_s(stream,"Name: %s\n",name);
	fprintf_s(stream,"Temperature: %.1f\n",temperature);
	fprintf_s(stream,"Grade: %c\n",grade);


	
	puts("����д��ɹ�!");

	char buffer[100];

	while (fgets(buffer,sizeof(buffer),stream) != NULL){
		printf("%s",buffer);
	}

	if (ferror(stream)) {
		perror("��ȡ�ļ�ʱ�����˴���!");
		clearerr(stream);
	}

	if (feof(stream)) {
		printf("�Ѿ������ļ���ĩβ...\n");
	}
	else {
		printf("�ļ�δ�ﵽĩβ�����ܷ����˴���...\n");
	}

	fclose(stream);
	return 0;
}