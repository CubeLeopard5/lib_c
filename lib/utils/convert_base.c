#include <stdlib.h>

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

int find_nb_in_base(const char nb, const char *base_digits)
{
    for (int i = 0; base_digits[i] != '\0'; i++) {
        if (nb == base_digits[i]) {
            return i;
        }
    }
    return -1;
}

int base_to_decimal(const char *number, const char *base_digits)
{
    int number_len = my_strlen(number);
    int base_len = my_strlen(base_digits);
    int rtn = 0;
    int power = 1;

    for (int i = number_len - 1; i >= 0; i--) {
        rtn += find_nb_in_base(number[i], base_digits) * power;
        power *= base_len;
    }
    return rtn;
}

char *decimal_to_base(int decimal, const char *base_digits)
{
    int base_len = my_strlen(base_digits);
    int tmp = decimal;
    int nb_digits = 0;
    char *rtn = NULL;

    while (tmp > 0) {
        tmp = tmp / base_len;
        nb_digits++;
    }
    rtn = malloc(sizeof(char) * nb_digits + 1);
    rtn[nb_digits] = '\0';
    for (int i = nb_digits - 1; i >= 0; i--) {
        rtn[i] = base_digits[decimal % base_len];
        decimal = decimal / base_len;
    }
    return rtn;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    return decimal_to_base(base_to_decimal(nbr, base_from), base_to);
}