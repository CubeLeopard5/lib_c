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
    int (*size)(const struct array_s *this);
    int (*whereis)(const struct array_s *this, const char *s);
    char *(*at)(const struct array_s *this, size_t pos);
    char *(*to_string)(const struct array_s *this, const char c);
    void (*push_back)(struct array_s *this, char *str);
} array_t;

void array_init(array_t *this, const char **t);
void array_destroy(array_t *this);

#endif