#include "sort.h"

/**
 * swap - Swaps two nodes
 * @head: Pointer to the head
 * @node1: Pointer to node to swap
 * @node2: Pointer to the second node to swap
 */

void swap(listint_t **head, listint_t **node, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev !+ NULL)
		(*node1)->prev->next = node2;

	else
		*head = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list
 * @list: The list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *tmp, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i++)
	{
		tmp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
