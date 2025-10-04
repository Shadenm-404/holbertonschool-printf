#include "main.h"

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
	int plus_flag, space_flag, hash_flag;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
			continue;
		}

		i++; /* skip % */
		if (!format[i])
			return (va_end(ap), -1);

		/* initialize flags */
		plus_flag = space_flag = hash_flag = 0;

		/* parse flags */
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

		/* handle specifiers */
		if (format[i] == 'd' || format[i] == 'i')
		{
			int n = va_arg(ap, int);

			if (n >= 0)
			{
				if (plus_flag)
					count += _putchar('+');
				else if (space_flag)
					count += _putchar(' ');
			}
			count += print_number(n);
		}
		else if (format[i] == 'c')
			count += _putchar(va_arg(ap, int));

		else if (format[i] == 's')
			count += print_string(va_arg(ap, char *));

		else if (format[i] == '%')
			count += _putchar('%');

		else if (format[i] == 'b')
			count += print_binary(va_arg(ap, unsigned int));

		else if (format[i] == 'p')
			count += print_pointer(va_arg(ap, void *));

		else if (format[i] == 'x' || format[i] == 'X')
		{
			unsigned int n = va_arg(ap, unsigned int);
			int upper = (format[i] == 'X');
			if (hash_flag && n != 0)
			{
				count += _putchar('0');
				count += _putchar(upper ? 'X' : 'x');
			}
			count += print_hex(n, upper);
		}
		else if (format[i] == 'o')
		{
			unsigned int n = va_arg(ap, unsigned int);
			if (hash_flag && n != 0)
				count += _putchar('0');
			count += print_octal(n);
		}
		else if (format[i] == 'u')
			count += print_unsigned(va_arg(ap, unsigned int));

		else
		{
			count += _putchar('%');
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
