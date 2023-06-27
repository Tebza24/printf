#include "main.h"

/**
 * print_char - Print a character
 * @args: va_list containing the character to print
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return write(1, &c, 1);
}

/**
 * print_string - Print a string
 * @args: va_list containing the string to print
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (str == NULL)
        str = "(null)";

    while (str[len] != '\0')
        len++;

    return write(1, str, len);
}

int print_percent(va_list args)
{
    (void)args; /* unused parameter */
    return write(1, "%", 1);
}
