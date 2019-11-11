#include "libmx.h"

int mx_list_size(t_list *list) {
	int size = 0;

	if (list) {
		t_list *new_node = list;

		while (new_node) {
			new_node = new_node->next;
			size++;
		}
	}

	return size;
}
