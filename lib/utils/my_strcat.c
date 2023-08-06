int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int idx = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++, idx++) {
        dest[idx] = src[i];
    }
    dest[idx] = '\0';
    return dest;
}