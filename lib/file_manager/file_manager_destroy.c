#include "./file_manager.h"

void file_manager_destroy(file_manager_t *this)
{
    if (this->fp) {
        fclose(this->fp);
    }
    if (this->str_content) {
        free(this->str_content);
    }
    if (this->word_tab_content != NULL) {
        for (int i = 0; this->word_tab_content[i] != NULL; i++) {
            free(this->word_tab_content[i]);
        }
        free(this->word_tab_content);
    }
    if (this->extension) {
        free(this->extension);
    }
    if (this->filename) {
        free(this->filename);
    }
    this->size = 0;
}