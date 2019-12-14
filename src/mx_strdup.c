#include "libmx.h"

char *mx_strdup(const char *s1) {
	char *newstr;

	if (!(newstr = mx_strnew(mx_strlen(s1))))
		return NULL;
	return newstr ? mx_strcpy(newstr, s1) : NULL;
}
