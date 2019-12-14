#include "libmx.h"

void mx_swap_str(char **data1, char **data2) {
	if (data1 && data2) {
		char *temp = *data1;
		
		*data1 = *data2;
		*data2 = temp;
	}
}
