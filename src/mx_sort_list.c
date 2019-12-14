#include "libmx.h"

static void swap(void **data1, void **data2) {
	void *temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
	if (lst && cmp) {
		for (t_list *node1 = lst; node1; node1 = node1->next){
			for (t_list *node2 = lst; node2->next; node2 = node2->next) {
				if (cmp(node2->data, node2->next->data))
					swap(&node2->data, &node2->next->data);
			}
		}
	}
	return lst;
}
