#include "F_memory_manager.h"
#include "F_logger.h"

void* safe_malloc(size_t size) {
	assert(size > 0);

	void* ptr = NULL;

	//C11
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
	ptr = aligned_alloc(alignof(max_align_t), size);
#else 
	//C11���������
	ptr = malloc(size);
#endif

	if (ptr == NULL) {
		//��ʵ��Ӧ���У����ܲ�ϣ���ڷ���ʧ��ʱֹͣ����
		//���ԣ�����ʹ�ö���Ϊ�˵��Է��㣬�ܹ���������
		//ʵ������ҵ��Ӧ�ø���������д�����

		fprintf(stderr, "Memory allocated failed for size %zu.\n", size);
		assert(ptr != NULL);
	}
	return ptr;
}

void* safe_remalloc(void* ptr, size_t newSize) {
	void* newPtr = realloc(ptr, newSize);
	if (!newPtr) {
		log_message(LOG_ERROR, "Failed to reallocate to %zu bytes of memory", newSize);
	}
	return newPtr;
}

void safe_free(void** ptr) {
	if (ptr && *ptr) {
		free(*ptr);
		*ptr = NULL;	//��ָ������ΪNULL����ֹҰָ��
	}
	else {
		log_message(LOG_WARNING, "Attempted to free a null or already freed pointer.");
	}
}