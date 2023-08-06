/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** kjhgfd
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct array_s
{
    char **tab;

    void (*print)(const struct array_s *this);

} array_t;

void array_init(array_t *this, const char **t);
void array_destroy(array_t *this);

#endif