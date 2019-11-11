#include "libmx.h"

void mx_pop_front(t_list **head) {
	if (head && *head) {
		t_list *new_node = *head;
		*head = new_node->next;
		free(new_node);
	}
}
