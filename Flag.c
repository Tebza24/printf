#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: parameter for formatted string for args
 * @i: parameter to take a parameter.
 * Return: active flags
 */
int get_flags(const char *format, int *i) {
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    int flags = 0;
    int curr_i = *i + 1;

    while (format[curr_i] != '\0') {
        int q = 0;

        while (FLAGS_CH[q] != '\0') {
            if (format[curr_i] == FLAGS_CH[q]) {
                flags |= FLAGS_ARR[q];
                break;
            }
            q++;
        }

        if (FLAGS_CH[q] == '\0') {
            break;
        }

        curr_i++;
    }

    *i = curr_i - 1;
    return flags;
}
