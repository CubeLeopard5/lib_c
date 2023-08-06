#include <stddef.h>

int my_strlen(char const *str);

double my_pow(double base, int exponent)
{
    double result = base;
    int absExponent = exponent > 0 ? exponent : exponent * -1;

    if (exponent == 0) {
        return 1.0;
    }
    for (int i = 1; i < absExponent; i++) {
        result *= base;
    }

    return exponent > 0 ? result : 1.0 / result;
}

char *my_strchr(const char *str, char c)
{
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

int convert_to_decimal(const char *str, const char *base, int baseLen)
{
    int decimal = 0;
    int len = my_strlen(str);
    int value = 0;
    char *ptr = NULL;

    for (int i = 0; i < len; i++) {
        ptr = my_strchr(base, str[i]);
        value = (ptr ? (ptr - base) : -1);
        if (value < 0 || value >= baseLen) {
            return 0;
        }
        decimal += value * my_pow(baseLen, len - i - 1);
    }

    return decimal;
}

int my_getnbr_base(char const *str, char const *base)
{
    int sign = 1;
    int startIndex = 0;
    int baseLen = my_strlen(base);

    while (str[startIndex] == '+' || str[startIndex] == '-') {
        if (str[startIndex] == '-')
            sign = sign * -1;
        startIndex++;
    }
    if (baseLen < 2 || baseLen > 36 || my_strchr(base, '-') || my_strchr(base, '+')) {
        return 0;
    }

    return convert_to_decimal(&str[startIndex], base, baseLen) * sign;
}