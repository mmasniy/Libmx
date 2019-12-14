#include "libmx.h"

int mx_arr_size(char **str) {
	int size = 0;

	for (int i = 0; str[i]; i++)
		size++;
	return size;
}
