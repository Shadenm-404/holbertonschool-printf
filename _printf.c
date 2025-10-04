#include "main.h"
#include <stdarg.h>
#include <limits.h>

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @s: string to print
 * Return: number of chars printed
 */
static int print_string(char *s)
{
	int count = 0;
	if (!s)
		s = "(null)";
	while (*s)
		count += _putchar(*s++);
	return (count);
}

/**
 * print_number - prints integer with flags (+, space)
 * @n: number to print
 * @plus: if + flag
 * @space: if space flag
 * Return: number of chars printed
 */
static int print_number(int n, int plus, int space)
{
	int count = 0;
	unsigned int num;

	if (n >= 0)
	{
		if (plus)
			count += _putchar('+');
		else if (space)
			count += _putchar(' ');
		num = n;
	}
	else
	{
		count += _putchar('-');
		num = -n;
	}
	if (num / 10)
		count += print_number(num / 10, 0, 0);
	count += _putchar((num % 10) + '0');
	return (count);
}

/**
 * print_unsigned - prints unsigned integer in base
 * @n: number
 * @base: base (8, 10, 16)
 * @hash: if # flag
 * @type: type for hex case (x, X)
 * Return: count
 */
static int print_unsigned(unsigned int n, int base, int hash, char type)
{
	int count = 0;
	char digits[] = "0123456789abcdef";
	char digitsX[] = "0123456789ABCDEF";

	if (hash && n != 0)
	{
		if (base == 8)
			count += _putchar('0');
		else if (base == 16 && type == 'x')
			count += write(1, "0x", 2);
		else if (base == 16 && type == 'X')
			count += write(1, "0X", 2);
	}
	if (n / base)
		count += print_unsigned(n / base, base, 0, type);
	if (type == 'X')
		count += _putchar(digitsX[n % base]);
	else
		count += _putchar(digits[n % base]);
	return (count);
}

/**
 * _printf - simplified printf
 * @format: format string
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;
	int plus, space, hash;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++, plus = space = hash = 0;
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				if (format[i] == '+')
					plus = 1;
				else if (format[i] == ' ')
					space = 1;
				else if (format[i] == '#')
					hash = 1;
				i++;
			}
			if (format[i] == 'c')
				count += _putchar(va_arg(ap, int));
			else if (format[i] == 's')
				count += print_string(va_arg(ap, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(ap, int), plus, space);
			else if (format[i] == 'u')
				count += print_unsigned(va_arg(ap, unsigned int), 10, 0, 'u');
			else if (format[i] == 'o')
				count += print_unsigned(va_arg(ap, unsigned int), 8, hash, 'o');
			else if (format[i] == 'x' || format[i] == 'X')
				count += print_unsigned(va_arg(ap, unsigned int), 16, hash, format[i]);
			else if (format[i] == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				if (format[i])
					count += _putchar(format[i]);
				else
					return (-1);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
