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
	char *s;

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
			{
				s = va_arg(ap, char *);
				if (s == NULL)
					s = "(null)";
				while (*s)
					count += _putchar(*s++);
			}
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
