#include "linked_list.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *current = NULL;

    if (*begin1 == NULL) {
        *begin1 = begin2;
    } else {
        current = *begin1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = begin2;
    }
}