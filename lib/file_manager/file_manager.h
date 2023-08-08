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
    char *extension;
    long size;

    void (*print_s)(const struct file_manager_s *this);
    void (*print_t)(const struct file_manager_s *this);
    int (*copy)(const struct file_manager_s *this, const char *dest_filename);
    int (*append)(struct file_manager_s *this, const char *src_filename);

} file_manager_t;

void file_manager_init(file_manager_t *this, const char *filename);
void file_manager_destroy(file_manager_t *this);

#endif