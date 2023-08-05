#include "linked_list.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *current = *begin;
    linked_list_t *prev = NULL;
    linked_list_t *temp;

    while (current != NULL) {
        if ((*cmp)(current->data, data_ref) == 0) {
            if (prev == NULL) {
                *begin = current->next;
            } else {
                prev->next = current->next;
            }
            temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return 0;
}