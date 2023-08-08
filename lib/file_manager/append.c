#include "./file_manager.h"

static int append(file_manager_t *this, const char *src_filename);

void free_file_str_content(file_manager_t *this);
void free_file_word_tab_content(file_manager_t *this);
void fill_str_content(file_manager_t *this);
void put_char_in_array_after_allocation(file_manager_t *this);
void allocate_array_mem(file_manager_t *this);

static int append(file_manager_t *this, const char *src_filename)
{
    FILE *src_file;
    int ch;

    if (this->fp) {
        src_file = fopen(src_filename, "r");
        if (src_file == NULL) {
            return -1;
        }
        fseek(this->fp, 0, SEEK_END);
        while ((ch = fgetc(src_file)) != EOF) {
            fputc(ch, this->fp);
        }
        fclose(src_file);
        free_file_str_content(this);
        fill_str_content(this);
        free_file_word_tab_content(this);
        this->word_tab_content = NULL;
        allocate_array_mem(this);
        put_char_in_array_after_allocation(this);
    }
    return 0;
}