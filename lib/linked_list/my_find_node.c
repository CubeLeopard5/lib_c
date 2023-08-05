#include "linked_list.h"

linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref, int (*cmp)())
{
    linked_list_t const *current = begin;

    while (current != NULL) {
        if ((*cmp)(current->data, data_ref)) {
            return (linked_list_t *)current;
        }
        current = current->next;
    }
    return NULL;
}