#include "main.h"

typedef struct conversion_specifier
{
    char specifier;
    int (*print)(va_list);
} conversion_specifier_t;

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_binary(va_list args);

int _printf(const char *format, ...)
{
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
            conversion_specifier_t conversion_specifiers[] = {
                {'c', print_char},
                {'s', print_string},
                {'%', print_percent},
                {'b', print_binary},
                {'\0', NULL}};

            int i = 0;
            while (conversion_specifiers[i].specifier != '\0')
            {
                if (format[len] == conversion_specifiers[i].specifier)
                {
                    printed += conversion_specifiers[i].print(args);
                    break;
                }
                i++;
            }

            if (conversion_specifiers[i].specifier == '\0')
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

int print_char(va_list args)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    return 1;
}

int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (str == NULL)
        str = "(null)";

    while (str[len])
    {
        write(1, &str[len], 1);
        len++;
    }

    return len;
}

int print_percent(va_list args)
{
    (void)args; // Unused argument
    write(1, "%", 1);
    return 1;
}

int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    unsigned int binary[32];
    int len = 0;

    if (num == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (num > 0)
    {
        binary[len] = num % 2;
        num /= 2;
        len++;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        char c = '0' + binary[i];
        write(1, &c, 1);
    }

    return len;
}
