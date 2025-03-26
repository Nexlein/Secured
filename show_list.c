/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** display a hashtable
*/

#include "include/my.h"
#include "include/hashtable.h"

void show_list(node_t *head)
{
    while (head != NULL) {
        mini_printf("> %d - %s\n", head->hash_key, head->value);
        head = head->next;
    }
}
