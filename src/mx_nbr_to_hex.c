#include "libmx.h"

static int mx_genlensixteen(unsigned long number) {
	unsigned long size = 0;
	unsigned long buffer = number;
	unsigned long num = 0;
	
	while(buffer) {
		num = buffer % 16;

		if (num > 0 && num <= 16)
			size++;
		buffer /= 16;
	}

	return size;
}
// создай файл для функций выше и ниже
static void to_hex(unsigned long number, char *hex) {
	unsigned long num = 0;
	int i = 0;

	while (number) {
		num = number % 16;
		
		if(num < 10) {
			hex[i] = num + 48;
			i++;
		}
		else if (num <= 16) {
			hex[i] = num + 87;
			i++;
		}
		number /= 16;
	}
}

char *mx_nbr_to_hex(unsigned long nbr) {
	char *hex = mx_strnew(mx_genlensixteen(nbr));
	if (nbr == 0)
		return mx_strcat(hex, "0");
	to_hex(nbr, hex);
	mx_str_reverse(hex);
	return hex;
}
