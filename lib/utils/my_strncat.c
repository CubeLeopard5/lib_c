int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int idx = my_strlen(dest);

    for (int i = 0; i < nb && src[i] != '\0'; i++, idx++) {
        dest[idx] = src[i];
    }
    dest[idx] = '\0';
    return dest;
}