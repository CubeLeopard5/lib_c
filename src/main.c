#include "../include/my.h"
#include "../include/string.h"
#include <stdio.h>

int main(void) {
    my_putchar('z');
    string_t string;
    string_init(&string, "lolol");
    printf("%s\n", string.c_str(&string));
    string_destroy(&string);
    return 0;
}