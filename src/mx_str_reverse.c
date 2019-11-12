#include "libmx.h"

void mx_str_reverse(char *s) {
	int len;

	if (s) {
		len = mx_strlen(s) - 1;
		for (int i = 0; i < len; i++, len--)
			mx_swap_char(&s[i], &s[len]);
	}
}
