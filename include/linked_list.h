#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *my_params_to_list(int ac, char * const *av);
int my_list_size(linked_list_t const *begin);
void my_rev_list(linked_list_t **begin);
int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *));
int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(), const void *data_ref, int (*cmp)());
linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref, int (*cmp)());

#endif