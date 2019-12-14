#include "libmx.h"

void mx_pop_front(t_list **head) {
	t_list *new_node = NULL;

	if (head && *head) {
		new_node = *head;
		*head = new_node->next;
		free(new_node);
	}
}
