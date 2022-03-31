#include "search.h"

/**
* linear_skip - adds an “express lane” to browse
* @list: pointer to the head of the skip list to search in
* @value: value to search for
* Return: pointer on the first node where value is located or NULL
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *result, *tmp;
	char string_message1[25] = "Value checked at index";
	char string_message2[35] = "Value found between indexes";

	if (!list)
		return (NULL);
	result = list;
	tmp = list;
	while (tmp->tmp)
	{
		result = tmp;
		tmp = tmp->tmp;
		printf("%s[%ld] = [%d]\n", string_message1, tmp->index, tmp->n);
		if (tmp->n >= value)
			break;
		if (tmp->tmp == NULL)
		{
			result = tmp;
			while (tmp->next)
				tmp = tmp->next;
		}
	}
	printf("%s[%ld] and [%ld]\n", string_message2, result->index, tmp->index);
	while (result->next && result->index != tmp->index)
	{
		printf("%s[%ld] = [%d]\n", string_message1, result->index, result->n);
		if (result->n >= value)
			break;
		result = result->next;
	}
	if (result->next == NULL)
		printf("%s[%ld] = [%d]\n", string_message1, result->index, result->n);
	if (result->n == value)
		return (result);
	return (NULL);
}
