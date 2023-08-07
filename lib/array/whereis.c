#include "./array.h"

static int whereis(const array_t *this, const char *s);

int my_strcmp(char const *s1, char const *s2);

static int whereis(const array_t *this, const char *s)
{
    if (this->tab != NULL) {
        for (int i = 0; this->tab[i] != NULL; i++) {
            if (my_strcmp(this->tab[i], s) == 0) {
                return i;
            }
        }
    }
    return -1;
}