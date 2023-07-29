#include <stdio.h>
#include <stdlib.h>
#include "./string.h"
#include <string.h>

static int to_int(const string_t *this);

int to_int(const string_t *this)
{
    return atoi(this->str);
}