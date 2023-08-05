#include "linked_list.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}

void my_print_list(linked_list_t *begin)
{
    linked_list_t *current = begin;
    while (current != NULL) {
        my_putstr((char*)current->data);
        if (current->next != NULL) {
            my_putstr("\n");
        }
        current = current->next;
    }
}