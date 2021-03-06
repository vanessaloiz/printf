#include "main.h"
int _printf(const char *format, ...);

/**
 * _printf - Function combines printers and makes a simple replica of print.
 * @format: Amount of arguments passed.
 * Return: count = length of argument.
 */
int _printf(const char *format, ...)
{
	int index = 0, count = 0;
	va_list list;

	if ((format == NULL) || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(list, format);

	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] == '%')
		{
			_putchar(format[index]);
			count++;
			index += 2;
			continue;
		}
		if (format[index] == '%' && format[index + 1] != '%')
		{
			if (format[index + 1] != 's' && format[index + 1] != 'c'
					&& format[index + 1] != 'd' && format[index + 1] != 'i')
			{
				_putchar(format[index]);
				count++;
				index++;
			}
			else
			{
				count += f_mod(format[index + 1], list);
				index += 2;
			}
		}
		else
		{
			_putchar(format[index]);
			count++;
			index++;
		}
	}
	va_end(list);
	return (count);
}
