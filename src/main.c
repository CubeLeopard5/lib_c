#include "../include/my.h"
#include "../include/string.h"
#include <stdio.h>
#include <math.h>

int main(void) {
    char dest[100] = "Hello";
    char src[100] = "Hello";

    printf("%d\n", my_strncmp(dest, src, 20));
    printf("%d\n", strncmp(dest, src, 20));
    return 0;
}