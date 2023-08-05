#include "linked_list.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *current = begin;

    while (current != NULL) {
        (*f)(current->data);
        current = current->next;
    }
    return 0;
}