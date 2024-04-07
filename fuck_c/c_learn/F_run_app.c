#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "F_types.h"
#include "F_application_logic.h"
#include "F_logger.h"

/*
* ��־����ϵͳ
* ģ��
* 1.��ƽ̨�Ļ�����������
* 2.��־ģ��
* 3.��־����ģ��
* 4.��װ�ڴ������ͷŰ�ȫ����
* 5.ͳһ��������ԣ���¼���󣬾��棬��������
* 6.���ָ��
* 7.������Ҫ�����߼�
*/

int main_log_system(void)
{
	//��ʼ��Ӧ�ó���

	if (!app_init()) {
		log_message(LOG_ERROR, "Application initialization failed.");
		logger_close();
		return EXIT_FAILURE;
	}

	if (!app_execute()) {
		log_message(LOG_ERROR, "Application execution failed.");
		app_cleanup();
		logger_close();
		return EXIT_FAILURE;
	}

	app_cleanup();
	logger_close();

	log_message(LOG_INFO, "Application exited successfully.");
	return EXIT_SUCCESS;
}