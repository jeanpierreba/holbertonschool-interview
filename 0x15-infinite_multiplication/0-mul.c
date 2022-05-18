#include "holberton.h"

int main(int argc, char *argv[])
{
	int length1 = 0, length2 = 0;
	char *num1 = argv[1], *num2 = argv[2], *product;

	if (argc != 3 || _is_number(num1) || _is_number(num2))
		error_message("Error");
	while (num1[length1])
		length1++;
	while (num2[length2])
		length2++;
	product = operation(num1, num2, length1, length2);
	if (product[0] == '0')
		_print(product + 1);
	else
		_print(product);
	free(product);
	return (0);
}

void error_message(char *message)
{
	_print(message);
	exit(98);
}

void _print(char *c)
{
	if (*c != '\0')
	{
		_putchar(*c);
		puts(c + 1);
	}
}

int _is_number(char *number)
{
	int i, digit = 0;

	for (i = 0; number[i] && !digit; i++)
	{
		if (number[i] < '0' || number[i] > '9')
			digit++;
	}
	return (digit);
}

char *operation(char *num1, char *num2, int length1, int length2)
{
	char *product;
	int i, j, sum, total_length = (length1 + length2);

	product = malloc (sizeof(char) * total_length);
	if (!product)
		error_message("Error");
	for (i = 0; i < total_length; i++)
		product[i] = '0';
	for (i = length1 - 1; i >= 0; i--)
	{
		sum = 0;
		for (j = length2 - 1; j >= 0; j--)
		{
			sum += (num1[i] - '0') * (num2[j] - '0');
			sum += product[i + j + 1] - '0';
			product[i + j + 1] = (sum % 10) + '0';
			sum /= 10;
		}
		if (sum)
			product[i + j + 1] = (sum % 10) + '0';
	}
	return product;
}
