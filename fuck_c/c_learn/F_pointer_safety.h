#pragma once

#include <stdbool.h>

bool is_nullptr(const void* ptr);

/*
* ��ȫ�ؽ�����ָ��
* ���ָ��ΪNULL����¼�����ҷ���ָ����Ĭ��ֵ
* @param ptr �������õ�ָ��
* @param defaultValue ������ʧ��ʱ��Ĭ��ֵ
* @return ָ��ָ���ֵ�����ָ��ΪNULL����ΪdefaulValue
*/
#define SAFE_DEREF(ptr,defaultValue) \ (is_nullptr(ptr) ? (log_error("Attempted to deference a NULL pointer."),defaultValue): *(ptr));