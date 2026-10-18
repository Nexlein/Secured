/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** unit_tests
*/

#include "../include/my.h"
#include "../include/hashtable.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_std(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test (mini_printf, mini_printf_char, .init=redirect_std)
{
    mini_printf("%c", 'c');
    cr_assert_stdout_eq_str("c");
}

Test (mini_printf, mini_printf_str, .init=redirect_std)
{
    mini_printf("%s", "Test passed");
    cr_assert_stdout_eq_str("Test passed");
}

Test (mini_printf, mini_printf_int, .init=redirect_std)
{
    mini_printf("%i %d", 68, -200);
    cr_assert_stdout_eq_str("68 -200");
}

Test (mini_printf, mini_printf_basic, .init=redirect_std)
{
    mini_printf("Test passed");
    cr_assert_stdout_eq_str("Test passed");
}

Test (my_stderr, stderr_basic, .init=redirect_std)
{
    my_stderr("Test passed");
    cr_assert_stderr_eq_str("Test passed");
}

Test (new_hashtable, new_hashtable_basic, .init=redirect_std)
{
    new_hashtable(&hash, 10);
}

Test (new_hashtable, new_hashtable_null, .init=redirect_std)
{
    new_hashtable(NULL, 10);
}

Test (new_hashtable, new_hashtable_len_zero, .init=redirect_std)
{
    new_hashtable(&hash, 0);
}

Test (new_hashtable, new_hashtable_negative_len, .init=redirect_std)
{
    new_hashtable(&hash, -4);
}

Test (new_hashtable, new_hashtable_all_null, .init=redirect_std)
{
    new_hashtable(NULL, 0);
}

Test (create_node, create_node_basic, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    create_node("key", "value", ht);
}

Test (create_node, create_node_null_key, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    create_node(NULL, "value", ht);
}

Test (create_node, create_node_null_value, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    create_node("key", NULL, ht);
}

Test (create_node, create_node_null_ht, .init=redirect_std)
{
    create_node("key", "value", NULL);
}

Test (create_node, create_node_all_null, .init=redirect_std)
{
    create_node(NULL, NULL, NULL);
}

Test (ht_insert, ht_insert_basic, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "test", "test passed");
}

Test (ht_insert, ht_insert_null_ht, .init=redirect_std)
{
    ht_insert(NULL, "test", "test passed");
}

Test (ht_insert, ht_insert_null_key, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, NULL, "test passed");
}

Test (ht_insert, ht_insert_null_value, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "test", NULL);
}

Test (ht_insert, ht_insert_null_all, .init=redirect_std)
{
    ht_insert(NULL, NULL, NULL);
}

Test (ht_dump, ht_dump_basic, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_dump(ht);
}

Test (ht_dump, ht_dump_null_ht, .init=redirect_std)
{
    ht_dump(NULL);
}

Test (ht_delete, ht_delete_basic, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_delete(ht, "test");
}

Test (ht_delete, ht_delete_null_ht, .init=redirect_std)
{
    ht_delete(NULL, "test");
}

Test (ht_delete, ht_delete_null_key, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_delete(ht, NULL);
}

Test (ht_delete, ht_delete_null_all, .init=redirect_std)
{
    ht_delete(NULL, NULL);
}

Test (ht_search, ht_search_basic, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_search(ht, "test");
}

Test (ht_search, ht_search_null_ht, .init=redirect_std)
{
    ht_search(NULL, "test");
}

Test (ht_search, ht_search_null_key, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_search(ht, NULL);
}

Test (ht_search, ht_search_null_all, .init=redirect_std)
{
    ht_search(NULL, NULL);
}

Test (hash, hash_basic, .init=redirect_std)
{
    hash("test", 7);
}

Test (hash, hash_null_key, .init=redirect_std)
{
    hash(NULL, 7);
}

Test (hash, hash_null_len, .init=redirect_std)
{
    hash("test", 0);
}

Test (hash, hash_negative_len, .init=redirect_std)
{
    hash("test", -4);
}

Test (delete_hashtable, delete_hashtable_basic, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    delete_hashtable(ht);
}

Test (delete_hashtable, delete_hashtable_null_ht, .init=redirect_std)
{
    delete_hashtable(NULL);
}

Test (ht_collision, colliding_keys_stay_separate, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    cr_assert_eq(hash("nexus", 10), hash("vision", 10));
    ht_insert(ht, "nexus", "first");
    ht_insert(ht, "vision", "second");
    cr_assert_str_eq(ht_search(ht, "nexus"), "first");
    cr_assert_str_eq(ht_search(ht, "vision"), "second");
    ht_insert(ht, "nexus", "updated");
    cr_assert_str_eq(ht_search(ht, "nexus"), "updated");
    cr_assert_str_eq(ht_search(ht, "vision"), "second");
    cr_assert_eq(ht_delete(ht, "vision"), 0);
    cr_assert_null(ht_search(ht, "vision"));
    cr_assert_str_eq(ht_search(ht, "nexus"), "updated");
    ht_insert(ht, "vision", "second");
    cr_assert_eq(ht_delete(ht, "nexus"), 0);
    cr_assert_null(ht_search(ht, "nexus"));
    cr_assert_str_eq(ht_search(ht, "vision"), "second");
    delete_hashtable(ht);
}

Test (ht_collision, key_is_copied, .init=redirect_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    char key[] = "nexus";

    ht_insert(ht, key, "value");
    key[0] = 'x';
    cr_assert_str_eq(ht_search(ht, "nexus"), "value");
    delete_hashtable(ht);
}
