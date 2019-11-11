#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
	int len_s1 = (int)strlen(s1);
	int i = 0;
	
	while(s2[i]){
		s1[len_s1] = s2[i];
		len_s1++;
		i++;
	}
	s1[len_s1] = '\0';
	return s1;
}
