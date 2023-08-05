#include <stdlib.h>

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *rtn = malloc(sizeof(char) * len + 1);

    for (int i = 0; src[i] != '\0'; i++) {
        rtn[i] = src[i];
    }
    rtn[len] = '\0';
    return rtn;
}