#include "lists.h"


/**
* check_cycle - checks if a linked list has a cycle
* @list: list we want to check
* Return: 1 if list has a cycle, 0 otherwise
*/
int check_cycle(listint_t *list)
{
	listint_t *tmp, *tmp2;

	tmp = tmp2 = list;
	while (tmp && tmp2 && tmp2->next)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next->next;
		if (tmp == tmp2)
			return (1);
	}
	return (0);
}
