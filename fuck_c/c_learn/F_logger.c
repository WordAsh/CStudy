#include "F_logger.h"
#include "F_types.h"

#include <stdio.h>
#include <time.h>
#include <errno.h>


static FILE* logFile = NULL;
static LogLevel currentLevel = LOG_INFO;

bool logger_init(const char* logFilePath) {
	if (logFilePath) {
		errno_t err = fopen_s(&logFile, logFilePath, "a");
		if (err != 0 || !logFile) {
			return false;
		}
	}
	else {
		logFile = stdout;
	}
	return true;
}

void logger_close(void) {
	if (logFile && logFile != stdout) {
		fclose(logFile);
	}
	logFile = NULL;
}

void log_message(LogLevel level, const char* format, ...) {
	if (level < currentLevel || !logFile) {
		return;		//�����־������ڵ�ǰ���õļ��𣬻�����־�ļ���δ�򿪣��򲻼�¼
	}

	time_t now = time(NULL);
	struct tm now_tm;
	localtime_s(&now_tm, &now);

	//��ӡʱ�������־����
	fprintf(logFile, "[%d-%02d-%02d %02d:%02d:%02d] ",
		now_tm.tm_year + 1900,
		now_tm.tm_mon + 1,
		now_tm.tm_mday,
		now_tm.tm_hour,
		now_tm.tm_min,
		now_tm.tm_sec);

	switch (level)
	{
	case LOG_DEBUG:fprintf(logFile, "[DEBUG] "); break;
	case LOG_INFO:fprintf(logFile, "[INFO] "); break;
	case LOG_WARNING:fprintf(logFile, "[WARNING] "); break;
	case LOG_ERROR:fprintf(logFile, "[ERROR] "); break;
	case LOG_FATAL:fprintf(logFile, "[FATAL] "); break;
	default:fprintf(logFile, "[UNKNOWN] "); break;
	}

	va_list args;
	va_start(args, format);
	vprintf(logFile, format, args);
	va_end(args);

	fprintf(logFile, "\n");
	fflush(logFile);	//ȷ����־��Ϣ������д��!
}

void set_log_level(LogLevel level) {
	currentLevel = level;
}