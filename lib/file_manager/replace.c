#include "./file_manager.h"

static void replace(file_manager_t *this, const char *to_find, const char *str);

int my_strlen(char const *str);

int get_nb_occurrences(char *str, const char *sub)
{
    int count = 0;
    int idx = 0;
    int len_sub = my_strlen(sub);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sub[idx]) {
            idx++;
        }
        if (len_sub == idx) {
            count++;
            idx = 0;
        }
    }
    return count;
}

int get_pos_next_substring(char *buffer, const char *to_find, int start)
{
    int len_to_find = my_strlen(to_find);
    int idx = 0;
    int n = -1;

    for (int i = start; buffer[i] != '\0'; i++) {
        if (buffer[i] == to_find[idx]) {
            idx++;
            if (n < 0) {
                n = i;
            }
        } else {
            idx = 0;
            n = -1;
        }
        if (idx == len_to_find) {
            return n;
        }
    }
    return -1;
}

char *my_replace_substring(char *buffer, const char *to_find, const char *replace)
{
    int nb_replacement = get_nb_occurrences(buffer, to_find);
    int len_buffer = my_strlen(buffer);
    int len_replace = my_strlen(replace);
    int len_to_find = my_strlen(to_find);
    char *rtn = malloc(sizeof(char) * (len_buffer + (nb_replacement * (len_replace - len_to_find)) + 1));
    int idx_sub = get_pos_next_substring(buffer, to_find, 0);
    int idx_rtn = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (i == idx_sub) {
            for (int j = 0; replace[j] != '\0'; j++) {
                rtn[idx_rtn++] = replace[j];
            }
            idx_sub = get_pos_next_substring(buffer, to_find, idx_sub + len_to_find);
            i += len_to_find - 1;
        } else {
            rtn[idx_rtn++] = buffer[i];
        }
    }
    rtn[idx_rtn] = '\0';
    return rtn;
}

static void replace(file_manager_t *this, const char *to_find, const char *str)
{
    int pos = this->get_pos(this, to_find);
    long remaining_content_length = 0;
    char *remaining_content = NULL;

    remaining_content_length = this->size - pos;
    fseek(this->fp, pos, SEEK_SET);
    remaining_content = malloc(sizeof(char) * (remaining_content_length + 1));
    fread(remaining_content, 1, remaining_content_length, this->fp);
    remaining_content[remaining_content_length] = '\0';
    remaining_content = my_replace_substring(remaining_content, to_find, str);
    fseek(this->fp, pos, SEEK_SET);
    ftruncate(fileno(this->fp), ftell(this->fp));
    fseek(this->fp, pos, SEEK_SET);
    fputs(remaining_content, this->fp);
    free(remaining_content);
    update_struct(this);
    
}