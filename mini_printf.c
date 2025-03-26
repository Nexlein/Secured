/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** mini_printf
*/

#include "include/my.h"

void find_pourcent(const char format, va_list list)
{
    switch (format) {
        case 'd':
            my_put_nbr(va_arg(list, int));
            break;
        case 'i':
            my_put_nbr(va_arg(list, int));
            break;
        case 's':
            my_putstr(va_arg(list, char *));
            break;
        case 'c':
            my_putchar((char)va_arg(list, int));
            break;
        case '%':
            my_putchar('%');
            break;
        default:
            break;
    }
}

int mini_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            find_pourcent(format[i + 1], list);
            i += 1;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(list);
    return 0;
}
