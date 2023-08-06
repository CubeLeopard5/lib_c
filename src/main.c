#include "../include/my.h"
#include "../include/string.h"
#include "../include/linked_list.h"
#include <stdio.h>
#include <math.h>

int main(void)
{
    char *str = "Hello world you are the best";
    char **tab = my_str_to_word_array(str, ' ');
    char *rtn = my_word_array_to_str(tab, ';');
    printf("%s\n", rtn);
    return 0;
}