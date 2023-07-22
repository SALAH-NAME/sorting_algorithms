#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: The list containing the nodes to swap
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * move_forwards - Moves forwards through the list and swaps adjacent elements
 * if they are in the wrong order
 *
 * @list: The list to sort
 * @current: The current position in the list
 *
 * Return: 1 if any swaps were made, 0 otherwise
 */
int move_forwards(listint_t **list, listint_t **current)
{
	int swapped = 0;

	while ((*current)->next != NULL)
	{
		if ((*current)->n > (*current)->next->n)
		{
			swap_nodes(list, *current, (*current)->next);
			swapped = 1;
			print_list(*list);
		}
		else
			*current = (*current)->next;
	}
	return (swapped);
}

/**
 * move_backwards - Moves backwards through the list and swaps adjacent elemnts
 * if they are in the wrong order
 *
 * @list: The list to sort
 * @current: The current position in the list
 *
 * Return: 1 if any swaps were made, 0 otherwise
 */
int move_backwards(listint_t **list, listint_t **current)
{
	int swapped = 0;

	while ((*current)->prev != NULL)
	{
		if ((*current)->n < (*current)->prev->n)
		{
			swap_nodes(list, (*current)->prev, *current);
			swapped = 1;
			print_list(*list);
		}
		else
			*current = (*current)->prev;
	}
	return (swapped);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: The list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list);
	while (swapped)
	{
		swapped = move_forwards(list, &current);
		if (!swapped)
			break;
		swapped = move_backwards(list, &current);
	}
}
