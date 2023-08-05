#include "linked_list.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *prev = NULL;
    linked_list_t *current = *begin;
    linked_list_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin = prev;
}