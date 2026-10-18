/*
** EPITECH PROJECT, 2024
** B-CPE-110 : Secured
** File description:
** my_strdup
*/

#include "include/hashtable.h"
#include "include/my.h"

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *copy = malloc(sizeof(char) * (len + 1));

    if (copy == NULL)
        return NULL;
    for (int i = 0; i <= len; i++)
        copy[i] = str[i];
    return copy;
}
