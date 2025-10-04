#include "main.h"
#include <limits.h>

/**
 * print_string - prints a string (handles NULL)
 * @s: string to print
 *
 * Return: number of characters printed
 */
static int print_string(char *s)
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
 *
 * Return: number of characters printed
 */
static int print_number(int n)
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
		{
			num = -num;
		}
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
 * print_binary_rec - helper that prints bits high->low
 * @n: number to print
 *
 * Return: number of characters printed
 */
static int print_binary_rec(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_binary_rec(n / 2);

	count += _putchar((char)('0' + (n & 1)));
	return (count);
}

/**
 * print_binary - prints an unsigned int as binary (base 2)
 * @n: number to print
 *
 * Return: number of characters printed
 */
static int print_binary(unsigned int n)
{
	if (n == 0)
		return (_putchar('0'));
	return (print_binary_rec(n));
}

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (va_end(ap), -1);

			if (format[i] == 'c')
				count += _putchar(va_arg(ap, int));
			else if (format[i] == 's')
				count += print_string(va_arg(ap, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(ap, int));
			else if (format[i] == 'b')
				count += print_binary(va_arg(ap, unsigned int));
			else if (format[i] == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
