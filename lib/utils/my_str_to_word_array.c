#include <stdlib.h>

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

char *str_in_tab(char *tab_place, char const *str, int start, int end)
{
    int j = 0;

    tab_place = malloc(sizeof(char) * (end - start));
    for (int i = start; str[i] != '\0' && i < end; i++, j++) {
        tab_place[j] = str[i];
    }
    tab_place[j] = '\0';
    return tab_place;
}

int get_nb_words(char const *str, char const c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    count++;
    return count;
}

char **my_str_to_word_array(char const *str, char const c)
{
    int count = get_nb_words(str, c);
    char **tab = NULL;
    int start = 0;
    int idx = 0;

    
    tab = malloc(sizeof(char *) * count);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            tab[idx] = str_in_tab(tab[idx], str, start, i);
            i++;
            idx++;
            start = i;
        }
    }
    tab[idx] = str_in_tab(tab[idx], str, start, my_strlen(str));
    idx++;
    tab[idx] = NULL;
    return tab;
}