#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	char *newnstr;

	n = n < (size_t)mx_strlen(s1) ? n : (size_t)mx_strlen(s1);
	newnstr = mx_strnew(n);
	if (newnstr) {
		newnstr[n] = '\0';
		while ((n--) > 0)
			newnstr[n] = s1[n];
	}
	return newnstr;
}
