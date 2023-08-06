#include <unistd.h>

int isprintable(char const str)
{
    if (!(str >= 32 && str <= 126)) {
        return 0;
    }
    return 1;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str);

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

int my_showstr(char const *str)
{
    char *base = "0123456789abcdef";

    for (int i = 0; str[i] != '\0'; i++) {
        if (isprintable(str[i])) {
            my_putchar(str[i]);
        } else {
            my_putchar('\\');
            if(str[i] < 16) {
				my_putchar('0');
			}
			my_putnbr_base(str[i], base);
        }
    }
    return my_strlen(str);
}