#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_print_comb(void)
{
    for (int i = 0; i <= 7; i++) {
        for (int j = i + 1; j <= 8; j++) {
            for (int k = j + 1; k <= 9; k++) {
                my_putchar(48 + i);
                my_putchar(48 + j);
                my_putchar(48 + k);
                if (i < 7) {
                    my_putchar(32);
                }
            }
        }
    }
    write(1, "\n", 1);
}