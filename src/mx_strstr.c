#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
	int len = mx_strlen(needle);

	if (!len)
		return (char *)haystack;
	
	while (*haystack) {
		if (*haystack == *needle) {
			if (mx_strncmp(haystack, needle, len) == 0)
				return (char *)haystack;
		}
		haystack++;
	}

	return 0;
}
