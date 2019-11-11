#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	char *newnstr;

	if (!(newnstr = mx_strnew(mx_strlen(s1))))
		return NULL;

	for (int i = 0; n > 0; n--, i++)
		newnstr[i] = s1[i];

	return newnstr;
}
