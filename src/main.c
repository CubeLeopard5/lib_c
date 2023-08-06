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
    array_init(&tab, t);
    tab.print(&tab);
    char *res = tab.to_string(&tab, '|');
    printf("RES = %s\n", res);
    free(res);
    array_destroy(&tab);
    return 0;
}