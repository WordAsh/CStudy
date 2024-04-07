//#define NDEBUG		//若定义NDEBUG，则所有assert不起作用。release时一定要define NDEBUG

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void processImage(int width, int height);


int main_assert(void)
{
	processImage(1024, 768);

	//模拟，假设w，h是通过其他函数，甚至是数组，指针传递的，那时，肉眼无法看到w，h的值
	int w = 50, h = 50;

	processImage(w, h);

	return EXIT_SUCCESS;
}

void processImage(int width, int height) {
	assert(width > 50 && width < 10000);
	assert(height > 50 && height < 10000);

	if (width > 50 && height > 50) {
		printf("Processing an image of size %dx%d pixels.\n", width, height);
	}
}