#include "./file_manager.h"

static void rename_file(file_manager_t *this, const char *str);

void set_filename(file_manager_t *this, const char *filename);

int my_strlen(char const *str);

char *str_concat(char *str1, char *str2)
{
    char *rtn = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int idx = 0;

    for (int i = 0; str1[i] != '\0'; i++, idx++) {
        rtn[idx] = str1[i];
    }
    for (int i = 0; str2[i] != '\0'; i++, idx++) {
        rtn[idx] = str2[i];
    }
    rtn[idx] = '\0';
    return rtn;
}

static void rename_file(file_manager_t *this, const char *str)
{
    char *begin = str_concat(this->filename, ".");
    char *end = str_concat(begin, this->extension);

    rename(end, str);
    free(this->filename);
    free(this->extension);
    set_filename(this, str);
    free(begin);
    free(end);
}