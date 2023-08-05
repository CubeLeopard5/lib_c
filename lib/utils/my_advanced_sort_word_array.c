#include <stddef.h>

int my_advanced_sort_word_array(char **tab, int (*cmp)(char const *, char const *))
{
    char *tmp = NULL;

    for (int i = 0; tab[i] != NULL && tab[i] != 0; i++) {
        for (int j = 0; tab[j + 1] != NULL && tab[j + 1] != 0; j++) {
            if (cmp(tab[j], tab[j + 1]) > 0) {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
    return 0;
}