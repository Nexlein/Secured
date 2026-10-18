/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** search in a hashtable
*/

#include "include/my.h"
#include "include/hashtable.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int hash_key = 0;
    int index = 0;
    node_t *tmp;

    if (ht == NULL || key == NULL || key[0] == '\0')
        return NULL;
    hash_key = ht->hash(key, ht->len);
    index = hash_key % ht->len;
    if (index < 0 || index > ht->len)
        return "Error: NULL key.";
    tmp = ht[index].head;
    while (tmp != NULL) {
        if (tmp->hash_key == hash_key && my_strcmp(tmp->key, key) == 0)
            return tmp->value;
        tmp = tmp->next;
    }
    return NULL;
}
