#include <time.h>
#include <inttypes.h>
#include <stdio.h>

int main_time()
{
	//��õ�ǰ��ʱ���
	time_t now = time(NULL);

	//ת���ɱ���ʱ��
	struct tm local_time;
	localtime_s(&local_time, &now);

	//ת����Э������ʱ(UTC)
	struct tm utc_time;
	gmtime_s(&utc_time, &now);

	char local_time_str[80];
	char utc_time_str[80];
	strftime(local_time_str, sizeof(local_time_str), "%Y-%m-%d %H:%M:%S",&local_time);

	strftime(utc_time_str, sizeof(utc_time_str), "%Y-%m-%d %H:%M:%S", &utc_time);

	printf("��ǰʱ���: %" PRIdMAX "\n", (intmax_t)now);

	printf("����ʱ�� %s\n", local_time_str);
	printf("UTCʱ�� %s\n", utc_time_str);

	return 0;
}