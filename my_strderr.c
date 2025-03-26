/*
** EPITECH PROJECT, 2024
** Organise
** File description:
** feur
*/

#include "include/my.h"

int my_stderr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
    return 0;
}
