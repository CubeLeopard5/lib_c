#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

int my_putnbr_base(int nbr, char const *base)
{
    int len = my_strlen(base);
    int	idx = nbr % len;

    if (nbr < 0) {
        my_putchar('-');
        my_putnbr_base(nbr * -1, base);
    }
    nbr = nbr / len;
    if (nbr > 0) {
        my_putnbr_base(nbr, base);
    }
    my_putchar(base[idx]);
    return nbr;
}