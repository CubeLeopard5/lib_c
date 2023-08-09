#include "./file_manager.h"
#include "print.c"
#include "copy.c"
#include "append.c"
#include "count.c"
#include "insert.c"
#include "rename_file.c"
#include "occurrence.c"
#include "get_pos.c"
#include "delete.c"
#include "replace.c"
#include "split.c"

size_t get_file_nb_lines(FILE *file)
{
    size_t line_count = 0;
    char ch;

    fseek(file, 0, SEEK_SET);
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_count++;
        }
    }
    return line_count + 1;
}

void allocate_array_mem(file_manager_t *this)
{
    size_t nb_lines = get_file_nb_lines(this->fp);
    char ch;
    int count = 0;
    int tab_idx = 0;

    fseek(this->fp, 0, SEEK_SET);
    this->word_tab_content = malloc(sizeof(char *) * (nb_lines + 1));
    while ((ch = fgetc(this->fp)) != EOF) {
        if (ch != '\n') {
            count++;
        } else if (ch == '\n') {
            this->word_tab_content[tab_idx] = malloc(sizeof(char) * (count + 1));
            tab_idx++;
            count = 0;
        }
    }
    if (count > 0) {
        this->word_tab_content[tab_idx] = malloc(sizeof(char) * (count + 1));
        count = 0;
    }
}

void put_char_in_array_after_allocation(file_manager_t *this)
{
    char ch;
    int tab_idx = 0;
    int line_idx = 0;

    fseek(this->fp, 0, SEEK_SET);
    while ((ch = fgetc(this->fp)) != EOF) {
        if (ch != '\n') {
            this->word_tab_content[tab_idx][line_idx] = ch;
            line_idx++;
        } else {
            this->word_tab_content[tab_idx][line_idx] = '\0';
            line_idx = 0;
            tab_idx++;
        }
    }
    if (line_idx > 0) {
        this->word_tab_content[tab_idx][line_idx] = '\0';
        tab_idx++;
    }
    this->word_tab_content[tab_idx] = NULL;
}

void set_filename(file_manager_t *this, const char *filename)
{
    int len_name = 0;
    int len_ext = 0;
    int dot = 0;

    for (int i = 0; filename[i] != '\0'; i++) {
        if (dot == 1) {
            len_ext++;
        }
        if (dot == 0 && filename[i] != '.') {
            len_name++;
        } else if (dot == 0 && filename[i] == '.') {
            dot = 1;
        }
    }
    this->filename = malloc(sizeof(char) * (len_name + 1));
    for (int i = 0; filename[i] != '.'; i++) {
        this->filename[i] = filename[i];
        this->filename[i + 1] = '\0';
    }
    this->extension = malloc(sizeof(char) * (len_ext + 1));
    for (int i = len_name + 1, j = 0; filename[i] != '\0'; i++, j++) {
        this->extension[j] = filename[i];
        this->extension[j + 1] = '\0';
    }
}

void fill_str_content(file_manager_t *this)
{
    this->size = 0;

    fseek(this->fp, 0, SEEK_END);
    this->size = ftell(this->fp);
    fseek(this->fp, 0, SEEK_SET);
    this->str_content = malloc(sizeof(char) * (this->size + 1));
    fread(this->str_content, 1, this->size, this->fp);
    this->str_content[this->size] = '\0';
}

void free_file_str_content(file_manager_t *this)
{
    if (this->str_content) {
        free(this->str_content);
    }
}

void free_file_word_tab_content(file_manager_t *this)
{
    if (this->word_tab_content != NULL) {
        for (int i = 0; this->word_tab_content[i] != NULL; i++) {
            free(this->word_tab_content[i]);
        }
        free(this->word_tab_content);
    }
}

void init_struct(file_manager_t *this)
{
    this->print_s = &print_s;
    this->print_t = &print_t;
    this->copy = &copy;
    this->append = &append;
    this->count = &count;
    this->insert_p = &insert_p;
    this->insert_l = &insert_l;
    this->rename_file = &rename_file;
    this->occurrence_f = &occurrence_f;
    this->occurrence = &occurrence;
    this->get_pos = &get_pos;
    this->get_next_pos = &get_next_pos;
    this->delete_c = &delete_c;
    this->replace = &replace;
    this->split = &split;
}

void file_manager_init(file_manager_t *this, const char *filename)
{
    if (filename != NULL && (this->fp = fopen(filename, "r+")) != NULL) {
        set_filename(this, filename);
        fill_str_content(this);
        this->word_tab_content = NULL;
        allocate_array_mem(this);
        put_char_in_array_after_allocation(this);
    } else {
        this->fp = NULL;
        this->word_tab_content = NULL;
        this->str_content = NULL;
        this->extension = NULL;
        this->size = 0;
    }
    init_struct(this);
}