#include "libmx.h"

char *mx_strtrim(const char *str) {
	int begin = 0;
	int index = 0;
	int finish;
	char *trimstr;

	if (!str)
		return NULL;

	finish = mx_strlen(str) - 1;

	for (int i = 0; mx_isspace(str[i]); i++, begin++);

	for (int i = finish; mx_isspace(str[i]); i--, finish--);

	if (begin > finish + 1)
		begin = finish;

	trimstr = mx_strnew(finish - begin + 1);
	
	if (!trimstr)
		return 0;

	if (!str[begin] || !str[finish] || begin >= finish)
		return (trimstr);

	for (; begin <= finish; begin++, index++)
		trimstr[index] = str[begin];

	trimstr[index] = '\0';

	return trimstr;
}
