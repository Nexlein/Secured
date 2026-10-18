/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured Bootstrap
** File description:
** my.h
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef MY_H
    #define MY_H
    #include "hashtable.h"

int my_putchar(char c);
int my_stderr(char *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *str);
char *my_inttostring(int num);
int my_putstr(char const *str);
int mini_printf(const char *format, ...);
void show_list(node_t *head);
void free_list(node_t *head);
int my_atoi(const char *str);
int my_atoi_char(char c);
int ht_replace(hashtable_t *ht, char *value, char *key);
node_t *create_node(char *key, char *value, hashtable_t *ht);

#endif /* MY_H */
