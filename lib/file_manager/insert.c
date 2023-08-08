#include "./file_manager.h"

static int count(const file_manager_t *this);

void update_struct(file_manager_t *this);
size_t get_file_nb_lines(FILE *file);

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

static void insert_l(file_manager_t *this, const char *str, size_t pos)
{
    size_t nb_lines = get_file_nb_lines(this->fp);
    char ch;
    int line_count = 0;
    int char_count = 0;

    fseek(this->fp, 0, SEEK_SET);
    if (pos > nb_lines) {
        pos = nb_lines;
    }
    while ((ch = fgetc(this->fp)) != EOF) {
        if (line_count == pos) {
            pos = char_count;
            break;
        }
        if (ch == '\n') {
            line_count++;
        }
        char_count++;
    }
    this->insert_p(this, str, pos);
}

static void insert_p(file_manager_t *this, const char *str, size_t pos)
{
    long remaining_content_length = 0;
    char *remaining_content = NULL;

    if (pos > this->size) {
        pos = this->size;
    }
    remaining_content_length = this->size - pos;
    fseek(this->fp, pos, SEEK_SET);
    remaining_content = malloc(sizeof(char) * (remaining_content_length + 1));
    fread(remaining_content, 1, remaining_content_length, this->fp);
    remaining_content[remaining_content_length] = '\0';
    fseek(this->fp, pos, SEEK_SET);
    fputs(str, this->fp);
    fputs(remaining_content, this->fp);
    this->size += my_strlen(str);
    free(remaining_content);
    update_struct(this);
}