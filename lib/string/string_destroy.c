/*
** EPITECH PROJECT, 2021
** dfghj
** File description:
** jhgfd
*/

#include <stdio.h>
#include <stdlib.h>
#include "./string.h"
#include <string.h>

void string_destroy(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
}