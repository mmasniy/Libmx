#include "libmx.h"

void mx_pop_back(t_list **head) {
	t_list *new_node = NULL;

	if (head && *head && (*head)->next) {
		new_node = *head;

		while (new_node->next->next)
			new_node = new_node->next;
		free(new_node->next);
		new_node->next = NULL;
	}
	else if (head && *head) {
		free(*head);
		*head = NULL;
	}
}
