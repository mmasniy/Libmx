#include "libmx.h"

int mx_count_words(const char *str, char c) {
	int i = 0;
	int count = 0;

	if (!str)
		return -1;
	while (str[i]) {
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return count;
}
