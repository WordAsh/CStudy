//#define NDEBUG		//������NDEBUG��������assert�������á�releaseʱһ��Ҫdefine NDEBUG

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void processImage(int width, int height);


int main_assert(void)
{
	processImage(1024, 768);

	//ģ�⣬����w��h��ͨ���������������������飬ָ�봫�ݵģ���ʱ�������޷�����w��h��ֵ
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