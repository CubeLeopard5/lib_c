#include <stdlib.h>

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    char *rtn = malloc(sizeof(char) * len);
    int j = 0;

    for (int i = len - 1; i >= 0; i--) {
        rtn[j] = str[i];
        j++;
    }
    rtn[j] = '\0';
    return rtn;
}