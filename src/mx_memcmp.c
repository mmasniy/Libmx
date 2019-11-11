#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	size_t i = 0;
	for (; i < n; i++)
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			break;

	if (i == n)
		return 0;
	return ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
}
