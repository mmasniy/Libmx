#include "libmx.h"

int mx_sqrt(int x) {
	int left = 0;
	int right = x;
	int middle = 0;
	int result;
	
	while (left <= right) {
		middle = left + (right - left) / 2;
		result = middle * middle;
		if (result == x)
			return middle;
		else if (result > x)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return 0;
}
