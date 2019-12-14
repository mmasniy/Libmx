#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	char *newstr;
	int i = -1;
	int j = -1;

	if (s1 && s2){
		newstr = mx_strnew(mx_strlen((char *)s1) + mx_strlen((char *)s2) + 1);
		if (!newstr)
			return NULL;
		while (s1[++i])
			newstr[i] = s1[i];
		while (s2[++j])
			newstr[i++] = s2[j];
		newstr[i] = '\0';
		return newstr;
	}
	else if (s1)
		return mx_strdup(s1);
	else if (s2)
		return mx_strdup(s2);
	return NULL;
}
