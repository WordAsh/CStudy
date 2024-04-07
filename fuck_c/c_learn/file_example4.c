#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>



int main_file4(void) 
{
	FILE* stream;

	long l;
	float fp;
	char s[81];
	char c;

	errno_t err = fopen_s(&stream, "C:\\Users\\Rigon\\Desktop\\123.txt", "r");
	if (err) {
		printf_s("The file was not opened.\n");
	}
	else {
		if (fscanf_s(stream,"%80s",s,(unsigned)_countof(s)) != 1) {
			printf("∂¡»°◊÷∑˚¥Æ ß∞‹!\n");
		}
		if (fscanf_s(stream,"%ld",&l) != 1) {
			printf("∂¡»°ld ß∞‹!\n");
		}
		if (fscanf_s(stream,"%f",&fp) != 1) {
			printf("∂¡»°lf ß∞‹!\n");
		}
		if (fscanf_s(stream," %c",&c,1) != 1) {
			printf("∂¡»°c ß∞‹!\n");
		}

		//Output
		printf("%s\n",s);
		printf("%ld\n",l);
		printf("%f\n",fp);
		printf("%c\n",c);

		fclose(stream);
	}



	return 0;
}