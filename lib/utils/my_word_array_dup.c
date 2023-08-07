#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

int my_get_word_array_len(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        count++;
    }
    return count;
}

char **my_word_array_dup(char **src)
{
    int len = my_get_word_array_len(src);
    char **tab = malloc(sizeof(char *) * (len + 1));

    for (int i = 0; src[i] != NULL; i++) {
        tab[i] = malloc(sizeof(char) * (my_strlen(src[i]) + 1));
        my_strcpy(tab[i], src[i]);
    }
    tab[len] = NULL;
    return tab;
}
