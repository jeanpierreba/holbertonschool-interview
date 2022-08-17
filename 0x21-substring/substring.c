#include "substring.h"

/**
* find_substring - finds all the possible substrings containing a list of words
* @s: string to scan
* @words: array of words
* @nb_words: number of elements in the array words
* @n: address at which to store the number of elements in the returned array
* Return: allocated array, storing each index in s
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *index, str_length = 0, word_length = 0, i;
	*n = 0;

	if (s == NULL || words == NULL || *words == NULL || nb_words == 0)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
		str_length++;
	for (i = 0; words[0][i] != '\0'; i++)
		word_length++;
	index = malloc(sizeof(int) * str_length);
	if (index == NULL)
		return (NULL);
	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (match(s + i, words, nb_words, word_length))
		{
			index[*n] = i;
			*n += 1;
		}
	}
	if (*n == 0)
	{
		free(index);
		return (NULL);
	}
	return (index);
}

/**
* match - looks if a substring match occurs
* @s: string to scan
* @words: array of words
* @nb_words: number of elements in the array words
* @word_length: length of each word of words array
* Return: 1 if a match of substring occurs, 0 otherwise
*/
int match(char const *s, char const **words, int nb_words, int word_length)
{
	int *done, done_length = 0, found, match = 1, i, j, k, not_in;

	done = malloc(sizeof(int) * nb_words);
	for (i = 0; i < nb_words; i++)
		done[i] = -1;
	for (j = 0; j < nb_words; j++)
	{
		found = 0;
		for (k = 0; k < nb_words; k++)
		{
			not_in = is_not_in(done, done_length, k);
			if (not_in && string_match((s + (j * word_length)), words[k]))
			{
				done[done_length] = k;
				done_length++;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			match = 0;
			break;
		}
	}
	free(done);
	return (match);
}

/**
* is_not_in - evaluates if a value is not in an array
* @arr: array we want to check in
* @length: length of the array
* @k: value we want to check
* Return: 1 if value is not found, 0 otherwise
*/
int is_not_in(int *arr, int length, int k)
{
	int i = 0;

	for (i = 0; i < length; i++)
	{
		if (arr[i] == k)
			return (0);
	}
	return (1);
}

/**
* string_match - tries to match the word with the substring
* @str: string
* @word: array of words that we want to match
* Return: 1 if wors is a substring of str, 0 otherwise
*/
int string_match(char const *str, char const *word)
{
	int i;

	for (i = 0; *(word + i) != '\0'; i++)
	{
		if (*(str + i) != *(word + i))
			return (0);
	}
	return (1);
}
