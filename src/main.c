#include "../include/my.h"
#include "../include/string.h"
#include <stdio.h>
#include <math.h>

int main(void) {
    char **tab = my_str_to_word_array("the anwser to the great question of the universe", ' ');
    my_show_word_array(tab);
    printf("\n");
    printf("\n");
    my_advanced_sort_word_array(tab, my_strcmp);
    //my_sort_word_array(tab);
    my_show_word_array(tab);

    return 0;
}