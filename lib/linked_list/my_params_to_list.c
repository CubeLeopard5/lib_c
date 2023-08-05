#include "linked_list.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *head = NULL;
    linked_list_t *current = NULL;
    linked_list_t *new_node = NULL;

    for (int i = 0; i < ac; i++) {
        new_node = malloc(sizeof(linked_list_t));
        new_node->data = av[i];
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
        } else {
            current->next = new_node;
        }
        current = new_node;
    }
    return head;
}