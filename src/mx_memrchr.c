#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	unsigned char *newstr = (unsigned char*)s + n;

	while (newstr != s) {
		if (*newstr == c)
			return (void *)newstr;
		else
			newstr--;
	}
	return NULL;
}
