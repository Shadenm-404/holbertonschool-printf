#include "main.h"

/**
 * print_string - prints a string (handles NULL)
 * @s: string to print
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
 * handle_specifier - handles one conversion specifier
 * @sp: specifier character
 * @ap: pointer to va_list
 * Return: number of characters printed
 */
static int handle_specifier(char sp, va_list *ap)
{
	if (sp == 'c')
		return (_putchar(va_arg(*ap, int)));
	if (sp == 's')
		return (print_string(va_arg(*ap, char *)));
	if (sp == '%')
		return (_putchar('%'));

	/* Unknown -> print literally, e.g. "%!" */
	_putchar('%');
	return (_putchar(sp));
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
			{
				va_end(ap);
				return (-1);
			}
			count += handle_specifier(format[i], &ap);
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
