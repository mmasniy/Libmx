#include "libmx.h"

char *mx_strsub(char const *s, unsigned int start, size_t len) {
	char *str;

	if (!s)
		return NULL;

	str = mx_strnew((int)len);

	if (!str)
		return NULL;

	str = mx_strncpy(str, &s[start], len);

	return str;
}
