#include "./file_manager.h"

static void delete_c(file_manager_t *this, int position, int n);

void update_struct(file_manager_t *this);

void remove_chars_from_buffer(char *buffer, int n) {
    size_t buffer_len = 0;

    if (buffer == NULL || n <= 0) {
        return;
    }
    buffer_len = my_strlen(buffer);
    if (n >= buffer_len) {
        buffer[0] = '\0';
        return;
    }
    memmove(buffer, buffer + n, buffer_len - n + 1);
}

static void delete_c(file_manager_t *this, int pos, int n)
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
    remove_chars_from_buffer(remaining_content, n);
    fseek(this->fp, pos, SEEK_SET);
    ftruncate(fileno(this->fp), ftell(this->fp));
    fseek(this->fp, pos, SEEK_SET);
    fputs(remaining_content, this->fp);
    free(remaining_content);
    update_struct(this);
}