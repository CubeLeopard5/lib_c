#include "linked_list.h"

void my_free_list(linked_list_t *begin)
{
    linked_list_t *temp = NULL;

    while (begin != NULL) {
        temp = begin;
        begin = begin->next;
        free(temp);
    }
}