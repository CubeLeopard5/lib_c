#include "../include/my.h"
#include "../include/string.h"
#include "../include/linked_list.h"
#include <stdio.h>
#include <math.h>

int print_data(void* data) {
    printf("%s\n", (char *)data);
    return 0;
}

int main(int argc, char* argv[]) {
    linked_list_t* list_head = my_params_to_list(argc, argv);

    printf("%d\n", my_list_size(list_head));

    my_rev_list(&list_head);

    my_apply_on_nodes(list_head, print_data);

    // Free allocated memory for the list
    while (list_head != NULL) {
        linked_list_t* temp = list_head;
        list_head = list_head->next;
        free(temp);
    }

    return 0;
}