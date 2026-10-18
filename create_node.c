/*
** EPITECH PROJECT, 2024
** workshop linked list
** File description:
** Task 01
*/

#include "include/my.h"
#include "include/hashtable.h"

/// @brief create a new node of a linked list
/// @param key information stored in the node
/// @param ht hashtable in which is the linkedlist
/// @return The new created node
node_t *create_node(char *key, char *value, hashtable_t *ht)
{
    node_t *new_node;

    if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
        return NULL;
    new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
        return NULL;
    new_node->key = my_strdup(key);
    if (new_node->key == NULL) {
        free(new_node);
        return NULL;
    }
    new_node->id = ht->save_id;
    ht->save_id++;
    new_node->value = value;
    new_node->hash_key = ht->hash(key, ht->len);
    new_node->next = NULL;
    return new_node;
}
