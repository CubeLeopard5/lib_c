#include "linked_list.h"

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    linked_list_t *sorted_list = NULL;
    linked_list_t *current = *begin;
    linked_list_t *next = NULL;
    linked_list_t *temp = NULL;

    while (current != NULL) {
        next = current->next;
        if (sorted_list == NULL || (*cmp)(current->data, sorted_list->data) < 0) {
            current->next = sorted_list;
            sorted_list = current;
        } else {
            temp = sorted_list;
            while (temp->next != NULL && (*cmp)(current->data, temp->next->data) >= 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *begin = sorted_list;
}