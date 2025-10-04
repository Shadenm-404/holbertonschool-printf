#include "main.h"
#include <limits.h>

int print_string(char *s)
{
	int n = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
		n += _putchar(*s++);
	return (n);
}

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

int print_unsigned(unsigned int n)
{
	int count = 0, i = 0, k;
	char buf[10];

	if (n == 0)
		return (_putchar('0'));

	while (n > 0)
	{
		buf[i++] = (char)('0' + (n % 10));
		n /= 10;
	}
	for (k = i - 1; k >= 0; k--)
		count += _putchar(buf[k]);
	return (count);
}

int print_octal(unsigned int n, int alt_prefix)
{
	int count = 0, i = 0, k;
	char buf[22];

	if (n == 0)
	{
		if (alt_prefix)
			return (_putchar('0') + _putchar('0'));
		return (_putchar('0'));
	}
	while (n > 0)
	{
		buf[i++] = (char)('0' + (n & 7));
		n >>= 3;
	}
	if (alt_prefix)
		count += _putchar('0');
	for (k = i - 1; k >= 0; k--)
		count += _putchar(buf[k]);
	return (count);
}

int print_hex(unsigned long n, int uppercase, int alt_prefix)
{
	int count = 0, i = 0, k;
	char buf[32];

	if (n == 0)
	{
		if (alt_prefix)
			return (_putchar('0') + _putchar(uppercase ? 'X' : 'x') + _putchar('0'));
		return (_putchar('0'));
	}
	while (n > 0)
	{
		unsigned int d = (unsigned int)(n & 0xF);
		if (d < 10)
			buf[i++] = (char)('0' + d);
		else
			buf[i++] = (char)((uppercase ? 'A' : 'a') + (d - 10));
		n >>= 4;
	}
	if (alt_prefix)
	{
		count += _putchar('0');
		count += _putchar(uppercase ? 'X' : 'x');
	}
	for (k = i - 1; k >= 0; k--)
		count += _putchar(buf[k]);
	return (count);
}

int print_binary(unsigned int n)
{
	int count = 0, i = 0, k;
	char buf[32];

	if (n == 0)
		return (_putchar('0'));
	while (n > 0)
	{
		buf[i++] = (char)('0' + (n & 1));
		n >>= 1;
	}
	for (k = i - 1; k >= 0; k--)
		count += _putchar(buf[k]);
	return (count);
}

int print_pointer(void *ptr)
{
	unsigned long v;
	int count = 0;

	if (ptr == NULL)
		return (print_string("(nil)"));

	v = (unsigned long)ptr;
	count += _putchar('0');
	count += _putchar('x');
	count += print_hex(v, 0, 0);
	return (count);
}
