#include "linked_list.h"

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    linked_list_t *current = NULL;

    new_node->data = data;
    new_node->next = NULL;
    if (*begin == NULL || (*cmp)(data, (*begin)->data) < 0) {
        new_node->next = *begin;
        *begin = new_node;
    } else {
        current = *begin;
        while (current->next != NULL && (*cmp)(data, current->next->data) >= 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}