#include "./file_manager.h"

static int get_pos(const file_manager_t *this, const char *to_find);

static int get_next_pos(const file_manager_t *this, const char *to_find, size_t pos);

int my_strlen(char const *str);

static int get_next_pos(const file_manager_t *this, const char *to_find, size_t pos)
{
    char ch;
    int idx = -1;
    int j = 0;
    int i = 0;

    fseek(this->fp, pos, SEEK_SET);
    while ((ch = fgetc(this->fp)) != EOF) {
        if (ch == to_find[i]) {
            i++;
            if (idx == -1) {
                idx = j;
            }
        } else {
            i = 0;
            idx = -1;
        }
        if (i == my_strlen(to_find)) {
            return idx;
        }
        j++;
    }
    return idx;
}

static int get_pos(const file_manager_t *this, const char *to_find)
{
    char ch;
    int idx = -1;
    int j = 0;
    int i = 0;

    fseek(this->fp, 0, SEEK_SET);
    while ((ch = fgetc(this->fp)) != EOF) {
        if (ch == to_find[i]) {
            i++;
            if (idx == -1) {
                idx = j;
            }
        } else {
            i = 0;
            idx = -1;
        }
        if (i == my_strlen(to_find)) {
            return idx;
        }
        j++;
    }
    return idx;
}