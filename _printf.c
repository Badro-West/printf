#include "main.h"
/**
 * _printf - our printf
 * @format: str
 * @...:
 * Return: int
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, index = 0, nubchar =0;
	va_list ar;
	char *buffer;

	va_start(ar, format);
	if (!format || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	if (format[i] == '\0')
		return (0);
	buffer = malloc(1024);
	if (buffer == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case '\0':
				printbuffer(buffer, index);
				free(buffer);
				va_end(ar);
				break;
			case 'c':
				index = add_to_buffer(va_arg(ar, int), buffer, index);
				i++;
				break;
			case 's':
				index = add_str_buffer(va_arg(ar, char *), buffer, index);
				i++;
				break;
			case 'i':
				index = add_int_buffer(va_arg(ar, int), buffer, index);
				i++;
				break;
			case 'd':
				index = add_int_buffer(va_arg(ar, int), buffer, index);
				i++;
				break;
			case '%':
				index = add_to_buffer('%', buffer, index);
				i++;
				break;
			case 'R':
				index = printrot13(va_arg(ar, char *), buffer, index);
				i++;
				break;
			default :
				index = add_to_buffer(format[i], buffer, index);
				break;
			}
		}
		else
			index = add_to_buffer(format[i], buffer, index);
		i++;
	}
	printbuffer(buffer, index);
	free(buffer);
	va_end(ar);	
	return (index + nubchar);
}
