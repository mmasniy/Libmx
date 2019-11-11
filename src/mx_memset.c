#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {

	size_t i = -1;
	unsigned char *a = (unsigned char *)b;

	while (++i < len)
		a[i] = c;
	return a;
}
