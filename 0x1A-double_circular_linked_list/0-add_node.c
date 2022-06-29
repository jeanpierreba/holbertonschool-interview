#include "list.h"

/**
* add_node_end - adds a new node to the end of the double circular linked list
* @list: List we want to modify
* @str: content of the new node
* Return: Adress of the new node or NULL
*/
List *add_node_end(List **list, char *str)
{
	List *new_node;

	new_node = create_new_node(str);

	if (!new_node)
		return (NULL);
	if (!(*list))
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		new_node->next = (*list);
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}
	return (new_node);
}

/**
* add_node_begin - add a new node to the beggining
* of the double circular linked list
* @list: List we want to modify
* @str: content of the new node
* Return: Adress of the new node or NULL
*/
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	new_node = create_new_node(str);
	if (!new_node)
		return (NULL);
	if (!(*list))
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		new_node->next = (*list);
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}
	return (new_node);
}

/**
* create_new_node - creates a new node
* @str: Content of the new node
* Return: Adress of the new node or NULL
*/
List *create_new_node(char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
