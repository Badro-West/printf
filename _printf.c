#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Printf function
 * @format: Format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char c;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str)
					{
						while (*str)
						{
							_putchar(*str);
							str++;
							count++;
						}
					}
					else
					{
						_putchar(' ');
						count++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		format++;
	}

	va_end(args);
	return count;
}

