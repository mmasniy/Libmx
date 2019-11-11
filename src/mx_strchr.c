#include "libmx.h"

char *mx_strchr(const char *s, int c){
	int	i = 0;

	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char*)&s[i]);
}
