/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** my_putchar
*/

#include <unistd.h>

/// @brief print a char
/// @param c char you want to print
int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}
