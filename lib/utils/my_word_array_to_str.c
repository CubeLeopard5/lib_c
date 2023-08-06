#include <stdlib.h>

int my_strlen(char const *str);

char *my_word_array_to_str(char **tab, char c)
{
    int size = 0;
    char *str = NULL;
    int idx = 0;
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        size = size + my_strlen(tab[i]);
        count++;
    }
    str = malloc(sizeof(char) * size + count + 1);
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++, idx++) {
            str[idx] = tab[i][j];
        }
        if (tab[i + 1] != NULL) {
            str[idx] = c;
            idx++;
        }
    }
    str[idx] = '\0';
    return str;
}