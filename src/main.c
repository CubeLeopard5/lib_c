#include "../include/my.h"
#include "../include/string.h"
#include "../include/linked_list.h"
#include "../include/array.h"
#include <stdio.h>
#include <math.h>

int main(void)
{
    array_t tab;
    const char *t[] = { "lol", "AAA", "dfghjkl", "dfghjAAdfghjk", NULL };
    array_init(&tab, t);
    //tab.print(&tab);
    tab.insert_c(&tab, 0, "AAZERTYUIO");
    tab.print(&tab);
    printf("\n\n");
    char **array = tab.occurrence(&tab, "AA", 2);
    for (int i = 0; array[i] != NULL; i++) {
        printf("ARRAY = %s\n", array[i]);
    }
    array_destroy(&tab);
    return 0;
}