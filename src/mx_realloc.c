#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	void *new_ptr = NULL;
	size_t len;
	
	if (size <= 0 && ptr) {
		free(ptr);
		return NULL;
	}
	if (!ptr && size)
		return malloc(size);

	len = malloc_size(ptr);
	if (len > size)
		new_ptr = (void *)malloc(len);
	else
		new_ptr = (void *)malloc(size);
	if (!new_ptr)
		return NULL;
	new_ptr = mx_memmove(new_ptr, ptr, size);
	free(ptr);
	return (void *)new_ptr;
}
