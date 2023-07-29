#include <stdio.h>
#include <stdlib.h>
#include "./string.h"
#include <string.h>

static char at(const string_t *this, size_t pos);

static char at(const string_t *this, size_t pos)
{
    if (this && pos > strlen(this->str))
        return (-1);
    return (this->str[pos]);
}