#include "main.h"

/**
 * _printf - Print output according to a format
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	{
    _printf("%b\n", 98);
    return (0);
}
    va_list args;
    int len = 0, printed = 0;

    va_start(args, format);

    while (format && format[len])
    {
        if (format[len] != '%')
        {
            write(1, &format[len], 1);
            printed++;
        }
        else if (format[len + 1])
        {
            len++;
            if (format[len] == 'c')
                printed += print_char(args);
            else if (format[len] == 's')
                printed += print_string(args);
            else if (format[len] == '%')
                printed += print_percent(args);
            else
            {
                write(1, &format[len - 1], 2);
                printed += 2;
            }
        }
        len++;
    }

    va_end(args);

    return printed;
}
