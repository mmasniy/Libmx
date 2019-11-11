#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
	size_t i = 0;
	unsigned char *newstr = (unsigned char *)s;
	char sym = (char)c;

	while (i < n){
		if (newstr[i] == sym)
			return &newstr[i];
		i++;
	}
	return NULL;
}
