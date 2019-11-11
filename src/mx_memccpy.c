#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	for (size_t i = 0; i < n; i++) {
		if (((unsigned char *)src)[i] == c) {
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			return (void *)&(((char *)dst)[i + 1]);
		}
		else
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return NULL;
}
