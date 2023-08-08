#include "./file_manager.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}

static void print_t(const file_manager_t *this);

static void print_t(const file_manager_t *this)
{
    if (this->word_tab_content != NULL) {
        for (int i = 0; this->word_tab_content[i] != NULL; i++) {
            my_putstr(this->word_tab_content[i]);
            if (this->word_tab_content[i] != NULL) {
                my_putstr("\n");
            }
        }
    }
}

static void print_s(const file_manager_t *this);

static void print_s(const file_manager_t *this)
{
    if (this->str_content) {
        my_putstr(this->str_content);
    }
}