#include "libmx.h"

char *mx_strncat (char *restrict dst, const char *restrict app, size_t n) {
	int i = 0;
	size_t j = 0;

	while (dst[i])
		i++;
	while (app[j] && (j < n))
		dst[i++] = app[j++];
	dst[i] = '\0';
	return (dst);
}
