#include "./file_manager.h"

static char **occurrence(file_manager_t *this, const char *str, size_t n);

int my_strlen(char const *str);

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

static char **occurrence(file_manager_t *this, const char *str, size_t n)
{
    char line[2048];
    int tab_idx = 0;
    int tab_len = 1;
    char **tab = malloc(sizeof(char *) * tab_len);

    tab[tab_idx] = NULL;
    fseek(this->fp, 0, SEEK_SET);
    while (fgets(line, sizeof(line), this->fp) != NULL) {
        if (n == tab_idx) {
            return tab;
        }
        if (strstr(line, str) != NULL) {
            tab = realloc(tab, sizeof(char *) * (tab_len + 1));
            tab[tab_idx] = my_strdup(line);
            tab_idx++;
            tab[tab_idx] = NULL;
        }
    }
    return tab;
}

static char *occurrence_f(file_manager_t *this, const char *str);

static char *occurrence_f(file_manager_t *this, const char *str)
{
    char line[2048];
    char *rtn = NULL;

    fseek(this->fp, 0, SEEK_SET);
    while (fgets(line, sizeof(line), this->fp) != NULL) {
        if (strstr(line, str) != NULL) {
            rtn = my_strdup(line);
            return rtn;
        }
    }
    return NULL;
}