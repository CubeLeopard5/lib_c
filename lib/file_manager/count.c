#include "./file_manager.h"

static int count(const file_manager_t *this);

static int count(const file_manager_t *this)
{
    size_t lineCount = 0;
    char ch;

    fseek(this->fp, 0, SEEK_SET);
    while ((ch = fgetc(this->fp)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }
    return lineCount + 1;
}