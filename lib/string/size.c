#include <stdio.h>
#include <stdlib.h>
#include "./string.h"
#include <string.h>

static int size(const string_t *this);

static int size(const string_t *this)
{
    if (this)
        return strlen(this->str);
    else
        return -1;
}