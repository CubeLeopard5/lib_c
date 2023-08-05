#include "../include/my.h"
#include "../include/string.h"
#include <stdio.h>
#include <math.h>

int main(void) {
    int color = 0xFF8040; // Replace AA, RR, GG, BB with appropriate values

    printf("Original Color: 0x%08X\n", color);

    int swapped_color = swap_endian_color(color);

    printf("Swapped Color: 0x%08X\n", swapped_color);

    return 0;
}