#include <time.h>
#include <inttypes.h>
#include <stdio.h>

int main_time()
{
	//获得当前的时间戳
	time_t now = time(NULL);

	//转换成本地时间
	struct tm local_time;
	localtime_s(&local_time, &now);

	//转换成协调世界时(UTC)
	struct tm utc_time;
	gmtime_s(&utc_time, &now);

	char local_time_str[80];
	char utc_time_str[80];
	strftime(local_time_str, sizeof(local_time_str), "%Y-%m-%d %H:%M:%S",&local_time);

	strftime(utc_time_str, sizeof(utc_time_str), "%Y-%m-%d %H:%M:%S", &utc_time);

	printf("当前时间戳: %" PRIdMAX "\n", (intmax_t)now);

	printf("本地时间 %s\n", local_time_str);
	printf("UTC时间 %s\n", utc_time_str);

	return 0;
}