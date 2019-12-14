#include "libmx.h"

char *mx_itoa(int number) {
	int len = mx_genlenn(number);
	char *str_number = mx_strnew(len);
	unsigned int new_number;
	
	new_number = number;
	if (number == 0)
		str_number[0] = 0;
	else if (number < 0) {
		len++;
		new_number = -number;
	}
	if (!(str_number))
		return NULL;
	str_number[--len] = new_number % 10 + '0';
	while(new_number /= 10)
		str_number[--len] = new_number % 10 + '0';
	if (number < 0)
		str_number[0] = '-';
	return str_number;
}
