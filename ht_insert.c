/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** insert in an hashtable
*/

#include "include/my.h"
#include "include/hashtable.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = 0;
    node_t *new_head;

    if (ht == NULL || key == NULL || key[0] == '\0')
        return 84;
    index = ht->hash(key, ht->len) % ht->len;
    if (index < 0 || index > ht->len || value == NULL)
        return 84;
    if (ht_replace(ht, value, key) == 0)
        return 0;
    new_head = create_node(key, value, ht);
    if (new_head == NULL)
        return 84;
    new_head->next = ht[index].head;
    ht[index].head = new_head;
    return 0;
}
