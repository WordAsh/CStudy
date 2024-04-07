#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>

int main_file2(void)
{
	FILE* file_stream;

	errno_t err = fopen_s(&file_stream, "C:\\Users\\Rigon\\Desktop\\test.txt", "w");

	if (err != 0 || file_stream == NULL) {
		perror("Failed to open file.");
		return EXIT_FAILURE;
	}

	fputc('H', file_stream);
	fputc('i', file_stream);
	fputc('\n', file_stream);

	fputs("This is a line written by fputs.\n", file_stream);

	double pi = 3.14;

	fprintf_s(file_stream, "This is format written. double pi equals %lf\n", pi);

	fclose(file_stream);

	puts("File 'test.txt' has been written successfully.");
	

	return 0;
}