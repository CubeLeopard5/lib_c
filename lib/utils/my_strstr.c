#include <stddef.h>

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;
    char *p = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[j]) {
            j++;
            if (p == NULL) {
                p = &str[i];
            }
        } else if (j == my_strlen(to_find)) {
            return p;
        } else {
            j = 0;
            p = NULL;
        }
    }
    return p;
}