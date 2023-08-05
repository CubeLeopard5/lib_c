#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

int my_sort_word_array(char **tab)
{
    char *tmp = NULL;

    for (int i = 0; tab[i] != NULL && tab[i] != 0; i++) {
        for (int j = 0; tab[j + 1] != NULL && tab[j + 1] != 0; j++) {
            if (my_strcmp(tab[j], tab[j + 1]) > 0) {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
    return 0;
}