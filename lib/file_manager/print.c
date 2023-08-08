#include "./file_manager.h"

static void print(const file_manager_t *this);

static void print(const file_manager_t *this)
{
    printf("STR = %s\n", this->str_content);
    if (this->word_tab_content != NULL) {
        for (int i = 0; this->word_tab_content[i] != NULL; i++) {
            printf("TAB = %s\n", this->word_tab_content[i]);
        }
    }
}