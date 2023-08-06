#include <stdlib.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
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