int my_getnbr(char const *str)
{
    int result = 0;
    int isneg = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            isneg = 1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - 48);
        } else if (result > 0) {
            break;
        } else {
            isneg = 0;
        }
    }
    if (isneg == 1) {
        return result * -1;
    }
    return result;
}