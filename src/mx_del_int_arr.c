#include "libmx.h"

void mx_del_int_arr(int **arr, int size) {
	int i = -1;

	while (++i < size)
		free(arr[i]);
	free(arr);
	arr = NULL;
}
