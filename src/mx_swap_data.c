#include "libmx.h"

void mx_swap_data(void **data1, void **data2) {
	if (data1 && data2) {
		void *temp = *data1;
		*data1 = *data2;
		*data2 = temp;
	}
}
