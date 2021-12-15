#include "lists.h"

/**
* insert_node - inserts a number into a sorted singly linked list.
* @head: head of the linked list
* @number: integer
* Return: address to the new node or NULL
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = malloc(sizeof(listint_t)), *tmp = *head;
	int i;

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = number;
	new_node->next = *head;
	for (i = 0; tmp;)
	{
		if (new_node->n > tmp->n)
		{
			i = new_node->n;
			new_node->n = tmp->n;
			tmp->n = i;
		}
		if (tmp->next && tmp->n > tmp->next->n)
		{
			i = tmp->n;
			tmp->n = tmp->next->n;
			tmp->next->n = i;
		}
		tmp = tmp->next;
	}
	*head = new_node;
	return (new_node);
}
