#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb <= 9 && nb >= 0) {
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
    } else {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
}