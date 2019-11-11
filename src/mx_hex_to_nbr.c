#include "libmx.h"

static int m_strlen(const char *str) {
	int i = 0;

	while (*str) {
		str++;
		i++;
	}
	return i;
}

unsigned long mx_hex_to_nbr(const char *hex) {
	int len = m_strlen(hex);
	unsigned long base = 1;
	unsigned long result = 0;

	for (int i = len - 1; i >= 0; i--, base *= 16) {
		if (hex[i] >= '0' && hex[i] <= '9')
			result += (hex[i] - 48) * base;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			result += (hex[i] - 55) * base;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			result += (hex[i] - 87) * base;
		else
			return 0;
	}
	return result;
}
