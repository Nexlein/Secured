/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** display a hashtable
*/

#include "include/my.h"
#include "include/hashtable.h"

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL) {
        my_stderr("Error: Nothing to display : NULL hashtable.\n");
        return;
    }
    for (int index = 0; index != ht->len; index++) {
        mini_printf("[%d]:\n", index);
        show_list(ht[index].head);
    }
}
