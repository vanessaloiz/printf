#include "main.h"
/**
 * print_char - Print a simple character.
 * @c: Character to be printed.
 * Return: On success 1.
 */
int print_char(char c)
{
	_putchar(c);
	return (1);
}

/**
 * print_str - Print a string of character.
 * @s: String to be printed.
 * Return: Length of string.
 */
int print_str(char *s)
{
	int idx;

	if (s == NULL)
		s = "(null)";

	for (idx = 0; s[idx] != '\0'; idx++)
		_putchar(s[idx]);
	return (idx);
}

/**
 * print_int - Print an integer.
 * @i: Integer to be printed.
 * @amt: Amount of integer to be printed.
 * Return: 0.
 */
int print_int(int i, int amt)
{
	unsigned int n = 0;

	if (i < 0) /* checks for negative numbers */
	{
		_putchar('-');
		amt++;
		n = (i * -1);
	}
	else
		n = i;

	if (n / 10 != 0)
		amt = print_int(n / 10, amt);

	_putchar(n % 10 + '0');
	amt++;
	return (amt);
}

/**
 * f_mod - Check which format modifier pass.
 * @mod: Format modifier pass.
 * @list: Reference to format modifier value.
 * Return: 0
 */
int f_mod(char mod, va_list list)
{
	switch (mod)
	{
		case 'c':
			return (print_char(va_arg(list, int)));
		case 'd':
		case 'i':
			return (print_int(va_arg(list, int), 0));
		case 's':
			return (print_str(va_arg(list, char *)));
	}
	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

