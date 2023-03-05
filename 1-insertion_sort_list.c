#include "sort.h"
/**
  * insertion_sort_list - function that sorts a doubly linked list
  * of integers in ascending order using the Insertion sort algorithm
  * @list: is data, double linked list
  * Return: nothing
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *element;

	if (list == NULL)
	{
		return;
	}
	element = (*list)->next;
	while (element)
	{
		while (element->prev && element->n < element->prev->n)
		{
			element->prev->next = element->next;
			if (element->next)
			{
				element->next->prev = element->prev;
			}
			element->next = element->prev;
			element->prev = element->prev->prev;
			element->next->prev = element;
			if (element->prev == NULL)
			{
				*list = element;
			}
			else
			{
				element->prev->next = element;
			}
			print_list(*list);
		}
		element = element->next;
	}
}
