/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** delete the hashtable
*/

#include "include/my.h"
#include "include/hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    hashtable_t *adress = ht;

    if (ht == NULL) {
        my_stderr("Error: NULL hashtable.\n");
        return;
    }
    if (ht->len <= 0) {
        my_stderr("Error: Incorect hashtable size, must be 1 or more.\n");
        return;
    }
    for (int index = 0; index != ht->len; index++) {
        free_list(ht[index].head);
    }
    ht = NULL;
    free(adress);
}
