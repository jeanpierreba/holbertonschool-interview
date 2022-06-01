#include "lists.h"


/**
* find_listint_loop - finds the loop in a linked list
* @head: Pointer to the head of the linked list
* Return: adress of the node where the loop starts or NULL
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tmp = head, *tmp2 = head;

	if (!head || !head->next)
		return (NULL);
	while (tmp2 && tmp2->next && tmp2->next->next)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next->next;
		if (tmp == tmp2)
		{
			tmp = head;
			while (tmp2 != NULL)
			{
				if (tmp == tmp2)
					return (tmp);
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
		}
	}
	return (NULL);
}
