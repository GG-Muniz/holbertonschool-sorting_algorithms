#include "sort.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * insertion_sort_list - sorts linked list of integers in ascending order.
 * @list: pointer to a pointer to list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			prev_node = temp->prev;

			if (prev_node->prev != NULL)
				prev_node->prev->next = temp;
			else
				*list = temp;

			temp->prev = prev_node->prev;

			prev_node->prev = temp;
			prev_node->next = temp->next;

			temp->next = prev_node;

			if (prev_node->next != NULL)
				prev_node->next->prev = prev_node;

			print_list(*list);
		}
	}
}
