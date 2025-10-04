#include "main.h"
#include <stdarg.h>
#include <limits.h>

/* Helpers */
static int print_number(int n);
static int print_hex(unsigned int n, int upper);
static int print_octal(unsigned int n);

/**
 * _printf - simplified printf with +, space, and # flags
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;
	int plus_flag = 0, space_flag = 0, hash_flag = 0;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			/* Check flags */
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				if (format[i] == '+')
					plus_flag = 1;
				else if (format[i] == ' ')
					space_flag = 1;
				else if (format[i] == '#')
					hash_flag = 1;
				i++;
			}

			/* Handle specifiers */
			if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(ap, int);
				if (num >= 0)
				{
					if (plus_flag)
						count += _putchar('+');
					else if (space_flag)
						count += _putchar(' ');
				}
				count += print_number(num);
			}
			else if (format[i] == 'o')
			{
				unsigned int num = va_arg(ap, unsigned int);
				if (hash_flag && num != 0)
					count += _putchar('0');
				count += print_octal(num);
			}
			else if (format[i] == 'x' || format[i] == 'X')
			{
				unsigned int num = va_arg(ap, unsigned int);
				if (hash_flag && num != 0)
				{
					count += _putchar('0');
					count += _putchar(format[i] == 'x' ? 'x' : 'X');
				}
				count += print_hex(num, format[i] == 'X');
			}
			else if (format[i] == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}

			plus_flag = space_flag = hash_flag = 0;
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

/* print decimal */
static int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += print_number(num / 10);
	count += _putchar((num % 10) + '0');
	return (count);
}

/* print octal */
static int print_octal(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += print_octal(n / 8);
	count += _putchar((n % 8) + '0');
	return (count);
}

/* print hex */
static int print_hex(unsigned int n, int upper)
{
	int count = 0;
	char c;

	if (n / 16)
		count += print_hex(n / 16, upper);

	c = (n % 16 < 10) ? (n % 16 + '0') :
		((upper ? 'A' : 'a') + (n % 16 - 10));
	count += _putchar(c);
	return (count);
}
