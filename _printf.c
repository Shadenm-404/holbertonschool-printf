#include "main.h"
#include <stdarg.h>
#include <limits.h>

/**
 * print_string - prints a string (handles NULL)
 * @s: string to print
 * Return: number of characters printed
 */
int print_string(char *s)
{
	int n = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		n += _putchar(*s);
		s++;
	}
	return (n);
}

/**
 * print_number - prints a signed decimal integer
 * @n: number to print
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0, i = 0, k, num = n;
	char buf[12];

	if (num == 0)
		return (_putchar('0'));

	if (num < 0)
	{
		count += _putchar('-');
		if (num == INT_MIN)
		{
			count += _putchar('2');
			num = 147483648;
		}
		else
			num = -num;
	}

	while (num > 0)
	{
		buf[i++] = (char)('0' + (num % 10));
		num /= 10;
	}
	for (k = i - 1; k >= 0; k--)
		count += _putchar(buf[k]);

	return (count);
}

/**
 * print_octal - prints an unsigned int as octal (with optional # flag)
 * @n: number to print
 * @alt_prefix: 1 if '#' flag, 0 otherwise
 * Return: number of characters printed
 */
int print_octal(unsigned int n, int alt_prefix)
{
	int count = 0, i = 0, k;
	char buf[32];

	if (n == 0)
		return (_putchar('0'));

	if (alt_prefix)
		count += _putchar('0');

	while (n > 0)
	{
		buf[i++] = (char)('0' + (n % 8));
		n /= 8;
	}
	for (k = i - 1; k >= 0; k--)
		count += _putchar(buf[k]);
	return (count);
}

/**
 * print_hex - prints an unsigned long as hexadecimal (supports # flag)
 * @n: number to print
 * @uppercase: 1 for %X, 0 for %x
 * @alt_prefix: 1 if '#' flag, 0 otherwise
 * Return: number of characters printed
 */
int print_hex(unsigned long n, int uppercase, int alt_prefix)
{
	int count = 0, i = 0, k;
	char buf[32];
	char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0)
		return (_putchar('0'));

	if (alt_prefix)
	{
		count += _putchar('0');
		count += _putchar(uppercase ? 'X' : 'x');
	}

	while (n > 0)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
	}
	for (k = i - 1; k >= 0; k--)
		count += _putchar(buf[k]);
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;
	int plus_flag = 0, space_flag = 0, hash_flag = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			plus_flag = space_flag = hash_flag = 0;

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

			if (format[i] == '\0')
				return (va_end(ap), -1);

			if (format[i] == 'c')
				count += _putchar(va_arg(ap, int));
			else if (format[i] == 's')
				count += print_string(va_arg(ap, char *));
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(ap, int);
				if (num >= 0 && plus_flag)
					count += _putchar('+');
				else if (num >= 0 && space_flag)
					count += _putchar(' ');
				count += print_number(num);
			}
			else if (format[i] == 'o')
				count += print_octal(va_arg(ap, unsigned int), hash_flag);
			else if (format[i] == 'x')
				count += print_hex(va_arg(ap, unsigned int), 0, hash_flag);
			else if (format[i] == 'X')
				count += print_hex(va_arg(ap, unsigned int), 1, hash_flag);
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
