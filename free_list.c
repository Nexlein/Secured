/*
** EPITECH PROJECT, 2024
** workshop linked list
** File description:
** task07
*/

#include "include/my.h"

void free_list(node_t *head)
{
    node_t *tmp = head;
    node_t *previous = NULL;

    while (tmp != NULL) {
        previous = tmp;
        tmp = tmp->next;
        free(previous);
    }
}
