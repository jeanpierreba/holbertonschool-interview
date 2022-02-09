#include "palindrome.h"

/**
* is_palindrome - checks whether or not a given integer is a palindrome
* @n: number to check
* Return: 1 if number is palindrome 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	int number = n, residue, reversed = 0;

	while (n != 0)
	{
		residue = n % 10;
		reversed = reversed * 10 + residue;
		n = n / 10;
	}
	if (number == reversed)
		return (1);
	return (0);
}
