#include "linked_list.h"

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(), const void *data_ref, int (*cmp)())
{
    linked_list_t *current = begin;

    while (current != NULL) {
        if ((*cmp)(current->data, data_ref)) {
            (*f)(current->data);
        }
        current = current->next;
    }
    return 0;
}