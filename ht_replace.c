/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** replace value in an hashtable
*/

#include "include/my.h"
#include "include/hashtable.h"

/// @brief Change the value already stored by a new one
/// @param ht hashtable where is the stored value
/// @param value the new value you want to place in ht
/// @param key The key of the old value you want to change
/// @return 0 if the value has been changed, 84 if the key have no value
int ht_replace(hashtable_t *ht, char *value, char *key)
{
    int hash_key = ht->hash(key, ht->len);
    int index = hash_key % ht->len;
    node_t *tmp = ht[index].head;

    while (tmp != NULL) {
        if (tmp->hash_key == hash_key) {
            tmp->value = value;
            return 0;
        }
        tmp = tmp->next;
    }
    return 84;
}
