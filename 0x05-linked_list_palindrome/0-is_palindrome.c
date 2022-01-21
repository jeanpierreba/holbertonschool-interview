#include "lists.h"

/**
* is_palindrome - checks if a singly linked list is a palindrome.
* @head: head of linked list
* Return: 1 if it is a palindrome, 0 otherwise
*/
int is_palindrome(listint_t **head)
{
	listint_t *temp, *temp2;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	temp = *head;
	while (temp->next)
		temp = temp->next;

	temp2 = *head;
	while (temp >= temp2)
	{
		if (temp2->n == temp->n)
		{
			temp2 = temp2->next;
			temp -= 2;
		}
		else
			return (0);
	}
	return (1);
}
