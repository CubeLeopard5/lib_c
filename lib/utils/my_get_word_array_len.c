#include <stddef.h>

int my_get_word_array_len(char const **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        count++;
    }
    return count;
}