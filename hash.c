/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** hash algoritm
*/

#include "include/hashtable.h"
#include "include/my.h"

int hash_loop(int hash_nb, char *key)
{
    for (int i = 0; key[i] != '\0'; i++)
        hash_nb += key[i] * key[i];
    return hash_nb;
}

int hash(char *key, int len)
{
    long int hash_nb = 1009;
    char *str_hash;

    if (key == NULL || len <= 0 || key[0] == '\0')
        return -1;
    hash_nb = hash_loop(hash_nb, key);
    str_hash = my_inttostring(hash_nb);
    if (my_strlen(str_hash) % 2 == 0) {
        hash_nb = my_atoi_char(str_hash[my_strlen(str_hash) / 2 - 1]) * 10;
        hash_nb += my_atoi_char(str_hash[my_strlen(str_hash) / 2]);
    } else if (my_strlen(str_hash) == 1)
        hash_nb = my_atoi_char(str_hash[0]);
    else {
        hash_nb = my_atoi_char(str_hash[my_strlen(str_hash) / 2 - 1]) * 100;
        hash_nb += my_atoi_char(str_hash[my_strlen(str_hash) / 2]) * 10;
        hash_nb += my_atoi_char(str_hash[my_strlen(str_hash) / 2 + 1]);
    }
    free(str_hash);
    hash_nb += (len * len) / (hash_nb / 2);
    return hash_nb;
}
