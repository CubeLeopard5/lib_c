#include <stddef.h>

int my_strlen(char const *str);

char get_upper_char(char c)
{
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    } else {
        return c;
    }
}

char *my_strcasestr(char *str, char const *to_find)
{
    int j = 0;
    char *p = NULL;
    char a;
    char b;

    for (int i = 0; str[i] != '\0'; i++) {
        a = get_upper_char(str[i]);
        b = get_upper_char(to_find[j]);
        if (a == b) {
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