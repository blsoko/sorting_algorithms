#include "sort.h"

/**
 * swap - insertion sort algorithm
 *
 * @list: head
 *
 * Return: the inserted node
 */

void swap(listint_t *list)
{
	listint_t *vector, *n_vector, *aux = NULL;

	if (list == NULL)
		return;
	if (list->next == NULL)
		return;

	vector = list;
	n_vector = list->next;

	aux = n_vector->next; /*let's swap the nodes.*/
	n_vector->next = vector;
	n_vector->prev = vector->prev;
	vector->next = aux;
	vector->prev = n_vector;

	if (n_vector->prev != NULL)
		(n_vector->prev)->next = n_vector;
	if (vector->next != NULL)
		(vector->next)->prev = vector;
}
/**
 * insertion_sort_list - insertion sort algorithm
 *
 * @list: head
 *
 * Return: the inserted node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	if (list == NULL)
		return;
	tmp1 = (*list)->next;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp1->prev != NULL)
		{
			if (tmp1->prev->n > tmp1->n)
			{
				swap(tmp1->prev);
				while ((*list)->prev != NULL)
					*list = (*list)->prev;
				print_list(*list);
			}
			else
			{
				break;
			}
		}
		tmp1 = tmp2;
	}
}
