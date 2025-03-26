/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** create a new hashtable
*/

#include "include/my.h"
#include "include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable;

    if (len <= 0 || hash == NULL) {
        my_stderr("Error: Incorect argument.\n");
        return NULL;
    }
    hashtable = malloc(sizeof(hashtable_t) * len);
    if (hashtable == NULL)
        return NULL;
    for (int index = 0; index != len; index++) {
        hashtable[index].hash = hash;
        hashtable[index].len = len;
        hashtable[index].save_id = 0;
        hashtable[index].head = NULL;
    }
    return hashtable;
}
