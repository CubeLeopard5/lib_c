#include "./file_manager.h"

static char **split(const file_manager_t *this, const char delimiter);

int my_strlen(char const *str);

char *str_in_tab(char *tab_place, char const *str, int start, int end)
{
    int j = 0;

    tab_place = malloc(sizeof(char) * (end - start + 1));
    for (int i = start; str[i] != '\0' && i < end; i++, j++) {
        tab_place[j] = str[i];
    }
    tab_place[j] = '\0';
    return tab_place;
}

int get_nb_words(char const *str, char const c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    count++;
    return count;
}

static char **split(const file_manager_t *this, const char delimiter)
{
    int count = get_nb_words(this->str_content, delimiter);
    char **tab = NULL;
    int start = 0;
    int idx = 0;

    tab = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; this->str_content[i] != '\0'; i++) {
        if (this->str_content[i] == delimiter) {
            tab[idx] = str_in_tab(tab[idx], this->str_content, start, i);
            i++;
            idx++;
            start = i;
        }
    }
    tab[idx] = str_in_tab(tab[idx], this->str_content, start, my_strlen(this->str_content));
    idx++;
    tab[idx] = NULL;
    return tab;
}