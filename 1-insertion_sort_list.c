#include "sort.h"

/**
 * node_swap - Swap two nodes in a_1 listint_t doubly-linked list.
 * @pointer_h: A pointer to the head of the doubly-linked list.
 * @pn1: A pointer to the first node to swap.
 * @pn2: The second node to swap.
 */
void node_swap(listint_t **pointer_h, listint_t **pn1, listint_t *pn2)
{
	(*pn1)->next = pn2->next;
	if (pn2->next != NULL)
		pn2->next->prev = *pn1;
	pn2->prev = (*pn1)->prev;
	pn2->next = *pn1;
	if ((*pn1)->prev != NULL)
		(*pn1)->prev->next = pn2;
	else
		*pointer_h = pn2;
	(*pn1)->prev = pn2;
	*pn1 = pn2->prev;
}

/**
 * insertion_sort_list - Sorts a_1 doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a_1 doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *put_in, *temp_var;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterator = (*list)->next; iterator != NULL; iterator = temp_var)
	{
		temp_var = iterator->next;
		put_in = iterator->prev;
		while (put_in != NULL && iterator->n < put_in->n)
		{
			node_swap(list, &put_in, iterator);
			print_list((const listint_t *)*list);
		}
	}
}
