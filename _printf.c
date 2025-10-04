#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
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

			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(ap, int));
					break;
				case 's':
					count += print_string(va_arg(ap, char *));
					break;
				case 'd':
				case 'i':
					count += print_number(va_arg(ap, int));
					break;
				case 'u':
					count += print_unsigned(va_arg(ap, unsigned int));
					break;
				case 'o':
					count += print_octal(va_arg(ap, unsigned int), 0);
					break;
				case 'x':
					count += print_hex(va_arg(ap, unsigned int), 0, 0);
					break;
				case 'X':
					count += print_hex(va_arg(ap, unsigned int), 1, 0);
					break;
				case 'b':
					count += print_binary(va_arg(ap, unsigned int));
					break;
				case 'p':
					count += print_pointer(va_arg(ap, void *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
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
