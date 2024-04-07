#pragma once

#include "F_types.h"
#include <stdarg.h>
#include <stdbool.h>


//��־����
typedef enum {
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR,
	LOG_FATAL
}LogLevel;

/*
* ��ʼ����־ģ��
* @params logFilePath ָ����־�ļ���·�������ΪNULL����־���������׼���
* @return �ɹ��ͷ���true������false
*/
bool logger_init(const char* logFilePath);

/*
* ��ֹ��־ģ��
*/
void logger_close(void);

/*
* д��־
* @param level ��־����
* @param format ��־��Ϣ�ĸ�ʽ�ַ�����printf
* @param ... �ɱ�����б��ṩ��ʽ���ַ���������
*/
void log_message(LogLevel level, const char* format, ...);


/*
* ���õ�ǰ��־����
* @param level �µ���־���� 
*/
void set_log_level(LogLevel level);