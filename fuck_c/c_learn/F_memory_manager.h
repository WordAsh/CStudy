#pragma once

#include "F_types.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
* ��ȫ�ط����ڴ�
* ����ڴ����ʧ�ܣ�����¼������־���ҷ���NULL
* 
* @param size ��Ҫ������ڴ��С��ʹ��size_t ��֤��ƽ̨������
* @return ָ������ڴ��ָ�룬�������ʧ����ΪNULL
*/
void* safe_malloc(size_t size);

/*
* ��ȫ�����·����ڴ�
* ����ڴ����ʧ�ܣ�����¼������־���ҷ���NULL
* @param ptr ԭ�ڴ�ָ��
* @param newSize �µ��ڴ��С
* @return ָ�����·�����ڴ�ָ�롣������·���ʧ����ΪNULL
*/
void* safe_remalloc(void* ptr, size_t newSize);

/*
* ��ȫ���ͷ��ڴ棬����ָ������ΪNULL
* �����ͷź�ʹ��Ұָ��
*/
void safe_free(void** ptr);