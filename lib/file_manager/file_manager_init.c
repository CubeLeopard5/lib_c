#include "./file_manager.h"
#include "print.c"

size_t get_file_nb_lines(FILE *file)
{
    size_t lineCount = 0;
    char ch;

    fseek(file, 0, SEEK_SET);
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }
    return lineCount + 1;
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

void fill_str_content(file_manager_t *this)
{
    long fileSize = 0;

    fseek(this->fp, 0, SEEK_END);
    fileSize = ftell(this->fp);
    fseek(this->fp, 0, SEEK_SET);
    this->str_content = malloc(sizeof(char) * (fileSize + 1));
    fread(this->str_content, 1, fileSize, this->fp);
    this->str_content[fileSize] = '\0';
}

void init_struct(file_manager_t *this)
{
    this->print = &print;
}

void file_manager_init(file_manager_t *this, const char *filename)
{
    if (filename != NULL) {
        this->fp = fopen(filename, "r");
        fill_str_content(this);
        this->word_tab_content = NULL;
        allocate_array_mem(this);
        put_char_in_array_after_allocation(this);
    } else {
        this->fp = NULL;
        this->word_tab_content = NULL;
    }
    init_struct(this);
}