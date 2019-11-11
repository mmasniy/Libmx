#include "libmx.h"

void mx_swap_int(int *data1, int *data2) {
	if (data1 && data2) {
		int temp = *data1;
		*data1 = *data2;
		*data2 = temp;
	}
}
