#include "F_memory_manager.h"
#include "F_logger.h"

void* safe_malloc(size_t size) {
	assert(size > 0);

	void* ptr = NULL;

	//C11
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
	ptr = aligned_alloc(alignof(max_align_t), size);
#else 
	//C11如果不可用
	ptr = malloc(size);
#endif

	if (ptr == NULL) {
		//在实际应用中，可能不希望在分配失败时停止程序
		//所以，这里使用断言为了调试方便，能够看到问题
		//实际在企业中应该根据需求进行错误处理

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
		*ptr = NULL;	//将指针设置为NULL，防止野指针
	}
	else {
		log_message(LOG_WARNING, "Attempted to free a null or already freed pointer.");
	}
}