#include "linked_list.h"

int my_list_size(linked_list_t const *begin)
{
    int count = 0;
    linked_list_t const *current = begin;

    while (current->next != NULL) {
        count++;
        current = current->next;
    }
    count++;
    return count;
}