#include <stdlib.h>
#include <unistd.h>

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL || tab[i] != 0; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            write(1, &tab[i][j], 1);
        }
        if (tab[i + 1] != NULL && tab[i + 1] != 0) {
            write(1, "\n", 1);
        }
    }
}