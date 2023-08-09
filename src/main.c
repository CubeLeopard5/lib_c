#include "../include/my.h"
#include "../include/string.h"
#include "../include/linked_list.h"
#include "../include/array.h"
#include "../include/file_manager.h"
#include <stdio.h>
#include <math.h>

int main(void)
{
    file_manager_t file;
    file_manager_init(&file, "file.txt");
    file.replace(&file, "er", "wakabonga");
    file.print_t(&file);
    file_manager_destroy(&file);
    return 0;
}