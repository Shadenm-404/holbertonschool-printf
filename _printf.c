#include "main.h"
#include <limits.h>

/* helper to print strings */
static int print_string(char *s)
{
	int n = 0;
	if (!s)
		s = "(null)";
	while (*s)
		n += _putchar(*s++);
	return (n);
}

/* helper to print numbers */
static int print_number(int n, int plus_flag, int space_flag)
{
	int count = 0;
	unsigned int num;

	if (n >= 0)
	{
		if (plus_flag)
			count += _putchar('+');
		else if (space_flag)
			count += _putchar(' ');
	}
	else
	{
		count += _putchar('-');
		num = -n;
	}
	if (n < 0)
		num = -n;
	else
		num = n;

	if (num / 10)
		count += print_number(num / 10, 0, 0);
	count += _putchar((num % 10) + '0');
	return (count);
}

/* helper for %# flag */
static int print_with_hash(unsigned int n, char type)
{
	int count = 0;

	if (type == 'x' && n != 0)
		count += print_string("0x");
	else if (type == 'X' && n != 0)
		count += print_string("0X");
	else if (type == 'o' && n != 0)
		count += _putchar('0');

	if (type == 'x' || type == 'X')
	{
		char hex[] = "0123456789abcdef";
		if (type == 'X')
			for (int i = 10; i < 16; i++)
				hex[i] = 'A' + (i - 10);
		if (n / 16)
			count += print_with_hash(n / 16, type);
		count += _putchar(hex[n % 16]);
	}
	else if (type == 'o')
	{
		if (n / 8)
			count += print_with_hash(n / 8, type);
		count += _putchar((n % 8) + '0');
	}
	return (count);
}

/* main printf function */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0, plus_flag = 0, space_flag = 0, hash_flag = 0;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			plus_flag = space_flag = hash_flag = 0;

			/* detect flags */
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

			if (format[i] == 'c')
				count += _putchar(va_arg(ap, int));
			else if (format[i] == 's')
				count += print_string(va_arg(ap, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(ap, int), plus_flag, space_flag);
			else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'o')
				count += print_with_hash(va_arg(ap, unsigned int), format[i]);
			else if (format[i] == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
