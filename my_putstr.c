/*
** EPITECH PROJECT, 2024
** task02
** File description:
** Day04 task02
*/

#include "include/my.h"

/// @brief print a char *
/// @param str string you want to print
int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
