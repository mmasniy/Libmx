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

char **mx_strsplit(char const *s, char c) {
	char	**newstr;
	int		i = -1;
	int		j = 0;
	int		a;

	if (!s || !(newstr = (char**)malloc(sizeof(*newstr)\
										* (mx_count_words(s, c) + 1))))
		return (NULL);
	while (++i < mx_count_words(s, c)) {
		a = 0;
		if (!(newstr[i] = mx_strnew(genlen(&s[j], c) + 1)))
			newstr[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			newstr[i][a++] = s[j++];
		newstr[i][a] = '\0';
	}
	newstr[i] = NULL;
	return newstr;
}
