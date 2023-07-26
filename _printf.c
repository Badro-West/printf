#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

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
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return -1;

    va_start(list, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            flags = 0; // Placeholder value for flags
            width = 0; // Placeholder value for width
            precision = 0; // Placeholder value for precision
            size = 0; // Placeholder value for size

            i++; // Move past '%'

            switch (format[i])
            {
                case 'c':
                    // 'c' conversion specifier: get the char from va_list and print
                    _putchar(va_arg(list, int));
                    printed_chars++;
                    break;
                case 's':
                    // 's' conversion specifier: get the string from va_list and print
                    {
                        char *str = va_arg(list, char *);
                        if (str)
                        {
                            while (*str)
                            {
                                _putchar(*str);
                                str++;
                                printed_chars++;
                            }
                        }
                        else
                        {
                            _putchar(' ');
                            printed_chars++;
                        }
                    }
                    break;
                case '%':
                    // Literal '%'
                    _putchar('%');
                    printed_chars++;
                    break;
                default:
                    // Invalid conversion specifier, treat it as a literal '%'
                    _putchar('%');
                    _putchar(format[i]);
                    printed_chars += 2;
                    break;
            }
        }
    }

    print_buffer(buffer, &buff_ind);
    va_end(list);
    return printed_chars;
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}

