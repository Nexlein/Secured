/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** delete in an hashtable
*/

#include "include/my.h"
#include "include/hashtable.h"

int search_onlinked(hashtable_t *ht, char *key)
{
    int hash_key = ht->hash(key, ht->len);
    int index = hash_key % ht->len;
    node_t *tmp = ht[index].head;
    node_t *prev = NULL;

    while (tmp != NULL) {
        if (tmp->hash_key == hash_key && my_strcmp(tmp->key, key) == 0) {
            prev->next = tmp->next;
            free(tmp->key);
            free(tmp);
            return 0;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    mini_printf("Nothing to delete at key: %s\n", key);
    return 84;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hash_key = 0;
    int index = 0;
    node_t *to_delete;

    if (ht == NULL || key == NULL || key[0] == '\0')
        return 84;
    hash_key = ht->hash(key, ht->len);
    index = hash_key % ht->len;
    if (index < 0 || index > ht->len)
        return 84;
    if (ht[index].head == NULL)
        return 84;
    if (ht[index].head->hash_key == hash_key
        && my_strcmp(ht[index].head->key, key) == 0) {
        to_delete = ht[index].head;
        ht[index].head = ht[index].head->next;
        free(to_delete->key);
        free(to_delete);
        return 0;
    }
    return search_onlinked(ht, key);
}
