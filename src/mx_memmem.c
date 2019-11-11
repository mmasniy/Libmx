#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	unsigned char *newbig = (unsigned char *)big;
	unsigned char *newlittle = (unsigned char *)little;

	if ((size_t)mx_strlen((const char *)newlittle) < little_len)
		return NULL;
	
	if (big_len > little_len && big_len > 0 && little_len > 0) {
		while (newbig) {
			if (mx_memcmp(newbig, newlittle, little_len) == 0)
				return (void *)newbig;
			newbig++;
		}
	}
	
	return NULL;
}
