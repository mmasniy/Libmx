#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
	int i = 0;

	while (len > i) {
		if (src[i])
			dst[i] = src[i];
		else
			while (i < len) {
				dst[i] = '\0';
				i++;
			}
		i++;
	}

	return dst;
}
