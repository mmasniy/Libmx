#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
	int l = left;
	int r = right;
	int swap = 0;
	char *pivot = !arr ? 0 : arr[left + (right - left) / 2];

	while (l++ <= r++) {
		for (; mx_strlen(arr[l]) < mx_strlen(pivot); l++);
		for (; mx_strlen(arr[r]) > mx_strlen(pivot); r--);

		if ( (l <= r) && (mx_strlen(arr[l]) > mx_strlen(arr[r]))) {
			mx_swap_str(&arr[l], &arr[r]);
			swap++;
		}
	}
	if (left < r)
	 	swap += mx_quicksort(arr, left, r);
	if (right > l)
	 	swap += mx_quicksort(arr, l, right);
	return swap;
}
