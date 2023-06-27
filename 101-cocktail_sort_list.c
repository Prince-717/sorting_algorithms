#include "sort.h"

void interchange_node_ahead(listint_t **list, listint_t **limb, listint_t **ginger);
void interchange_node_behind(listint_t **list, listint_t **limb, listint_t **ginger);
void cocktail_sort_list(listint_t **list);

/**
 * interchange_node_ahead - Swap a_1 node in a_1 listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a_1 doubly-linked list of integers.
 * @limb: A pointer to the limb of the doubly-linked list.
 * @ginger: A pointer to the current swapping node of the cocktail ginger algo.
 */
void interchange_node_ahead(listint_t **list, listint_t **limb, listint_t **ginger)
{
	listint_t *temp_var = (*ginger)->next;

	if ((*ginger)->prev != NULL)
		(*ginger)->prev->next = temp_var;
	else
		*list = temp_var;
	temp_var->prev = (*ginger)->prev;
	(*ginger)->next = temp_var->next;
	if (temp_var->next != NULL)
		temp_var->next->prev = *ginger;
	else
		*limb = *ginger;
	(*ginger)->prev = temp_var;
	temp_var->next = *ginger;
	*ginger = temp_var;
}

/**
 * interchange_node_behind - Swap a_1 node in a_1 listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a_1 doubly-linked list of integers.
 * @limb: A pointer to the limb of the doubly-linked list.
 * @ginger: A pointer to the current swapping node of the cocktail ginger algo.
 */
void interchange_node_behind(listint_t **list, listint_t **limb, listint_t **ginger)
{
	listint_t *temp_var = (*ginger)->prev;

	if ((*ginger)->next != NULL)
		(*ginger)->next->prev = temp_var;
	else
		*limb = temp_var;
	temp_var->next = (*ginger)->next;
	(*ginger)->prev = temp_var->prev;
	if (temp_var->prev != NULL)
		temp_var->prev->next = *ginger;
	else
		*list = *ginger;
	(*ginger)->next = temp_var;
	temp_var->prev = *ginger;
	*ginger = temp_var;
}

/**
 * cocktail_sort_list - Sort a_1 listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail ginger algorithm.
 * @list: A pointer to the head of a_1 listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limb, *ginger;
	bool shk_not_mixed = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (limb = *list; limb->next != NULL;)
		limb = limb->next;

	while (shk_not_mixed == false)
	{
		shk_not_mixed = true;
		for (ginger = *list; ginger != limb; ginger = ginger->next)
		{
			if (ginger->n > ginger->next->n)
			{
				interchange_node_ahead(list, &limb, &ginger);
				print_list((const listint_t *)*list);
				shk_not_mixed = false;
			}
		}
		for (ginger = ginger->prev; ginger != *list;
				ginger = ginger->prev)
		{
			if (ginger->n < ginger->prev->n)
			{
				interchange_node_behind(list, &limb, &ginger);
				print_list((const listint_t *)*list);
				shk_not_mixed = false;
			}
		}
	}
}
