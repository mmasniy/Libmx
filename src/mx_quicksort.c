#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
	int l = left;
	int r = right;
	int swap = 0;
	char *pivot = arr[left + (right - left) / 2];

	if (!arr)
		return -1;

	while (l < r) {
		for (; mx_strlen(arr[l]) < mx_strlen(pivot); l++);

		for (; mx_strlen(arr[r]) > mx_strlen(pivot); r--);

		if (l <= r)
			if (mx_strlen(arr[l]) > mx_strlen(arr[r])) {
				mx_swap_str(arr + (l++), arr + (r--));
				swap++;
			}

	}

	if (swap) {
        swap = l < right ? mx_quicksort(arr, l, right) : 0;
        swap += left < r ? mx_quicksort(arr, left, r) : 0;
    }

    return 1 + swap;
}
