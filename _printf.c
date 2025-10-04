#include "main.h"

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
			continue;
		}

		i++; /* skip '%' */
		if (format[i] == '\0')
			return (va_end(ap), -1);

		/* flags: '+', ' ', '#' — do not consume space unless converter is d/i */
		{
			int plus = 0, space = 0, hash = 0, done = 0;

			while (!done)
			{
				if (format[i] == '+')
				{
					plus = 1; i++;
				}
				else if (format[i] == '#')
				{
					hash = 1; i++;
				}
				else if (format[i] == ' ')
				{
					int j = i;
					while (format[j] == ' ')
						j++;
					if (format[j] == 'd' || format[j] == 'i')
					{
						space = 1; i++;
					}
					else
					{
						done = 1; /* leave the space to be printed literally below */
					}
				}
				else
				{
					done = 1;
				}
			}

			if (format[i] == 'c')
				count += _putchar(va_arg(ap, int));
			else if (format[i] == 's')
				count += print_string(va_arg(ap, char *));
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int n = va_arg(ap, int);
				if (n >= 0)
				{
					if (plus) count += _putchar('+');
					else if (space) count += _putchar(' ');
				}
				count += print_number(n);
			}
			else if (format[i] == 'u')
				count += print_unsigned(va_arg(ap, unsigned int));
			else if (format[i] == 'o')
			{
				unsigned int u = va_arg(ap, unsigned int);
				count += print_octal(u, hash && u != 0);
			}
			else if (format[i] == 'x' || format[i] == 'X')
			{
				unsigned int u = va_arg(ap, unsigned int);
				int upper = (format[i] == 'X');
				count += print_hex(u, upper, hash && u != 0);
			}
			else if (format[i] == 'p')
				count += print_pointer(va_arg(ap, void *));
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
		i++;
	}
	va_end(ap);
	return (count);
}
