#include "../include/my.h"
#include "../include/string.h"
#include "../include/linked_list.h"
#include "../include/array.h"
#include <stdio.h>
#include <math.h>

int main(void)
{
    array_t tab;
    const char *t[] = { "lol", "AAA", "dfghjkl", NULL };
    array_t tab2;
    const char *t2[] = { "zz", "xx", "yy", "ww", NULL };
    array_init(&tab, t);
    array_init(&tab2, t2);
    tab.print(&tab);
    tab.insert_c(&tab, 1, "Aloha");
    tab.delete(&tab, 0);
    tab.sort(&tab, my_strcmp);
    tab.merge_t(&tab, &tab2);
    printf("\n\n");
    tab.print(&tab);
    array_destroy(&tab);
    array_destroy(&tab2);
    return 0;
}