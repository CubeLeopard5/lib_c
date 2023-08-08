#include "./file_manager.h"

static int copy(const file_manager_t *this, const char *dest_filename);

static int copy(const file_manager_t *this, const char *dest_filename)
{
    FILE *destination_file;
    int ch;

    if (this->fp) {
        destination_file = fopen(dest_filename, "w");
        if (destination_file == NULL) {
            return -1;
        }
        fseek(this->fp, 0, SEEK_SET);
        while ((ch = fgetc(this->fp)) != EOF) {
            fputc(ch, destination_file);
        }
        fclose(destination_file);
    }
    return 0;
}