#include "libmx.h"

static int genlen(const char *str, char c) {
	int i = 0;
	int len = 0;

	while (str[i] == c)
		i++;

	while(str[i] != c && str[i]) {
		i++;
		len++;
	}
	return len;
}

char **mx_strsplit(const char *s, char c) {
	int i = -1;
	int j = 0;
	int a;
	char **str;

	if (!s)
		return NULL;

	if (!(str = (char **)malloc(sizeof(*str) * mx_count_words(s, c) + 1)))
		return NULL;
	while (++i < mx_count_words(s, c)) {
		a = 0;

		str[i] = mx_strnew(genlen(&s[j], c));

		while (s[j] == c)
			j++;
		while (s[j] != c && s[j]) {
			str[i][a++] = s[j++];
		}
		str[i][a] = '\0';
	}
	str[i] = NULL;
	return str;
}
