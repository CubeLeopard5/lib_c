#include <stdio.h>
#include <stdlib.h>
#include "./string.h"
#include <string.h>

static void clear(string_t *this);

static void clear(string_t *this)
{
    free(this->str);
    this->str = '\0';
}