#include "F_pointer_safety.h"
#include "F_error_handling.h"

bool is_nullptr(const void* ptr) {
	if (ptr == NULL) {
		log_error("Detected a NULL pointer.");
		return true;
	}

	return false;
}