int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int j = my_strlen(src);

    for (; i < n && i < j; i++) {
        dest[i] = src[i];
    }
    if (n <= j) {
        dest[i] = '\0';
    }
    return dest;
}