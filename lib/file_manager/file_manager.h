/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** kjhgfd
*/

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct file_manager_s
{
    FILE *fp;
    char *str_content;
    char **word_tab_content;
    char *filename;

    void (*print)(const struct file_manager_s *this);

} file_manager_t;

void file_manager_init(file_manager_t *this, const char *filename);
void file_manager_destroy(file_manager_t *this);

#endif