#include <stdio.h>
#include <stdlib.h>
#include "./string.h"
#include <string.h>

static const char *c_str(const string_t *this);

const char *c_str(const string_t *this)
{
    return (this->str);
}