/*
** EPITECH PROJECT, 2024
** string to int
** File description:
** convert a string into a int
*/

#include "include/hashtable.h"
#include "include/my.h"
/// @brief cast a string into an int
/// @param str only number composed string tou want to turn into int
/// @return your string into int
int my_atoi(const char *str)
{
    int result = 0;
    int i = 0;

    if (str == NULL || str[0] == '\0') {
        return 84;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 84;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int my_atoi_char(char c)
{
    int result = 0;

    if (c < '0' || c > '9')
        return 84;
    result = result + (c - '0');
    return result;
}
