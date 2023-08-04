char *my_strcapitalize(char *str)
{
    int begining_of_word = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && begining_of_word == 1) {
            str[i] -= 32;
            begining_of_word = 0;
        } else if (str[i] >= 'A' && str[i] <= 'Z' && begining_of_word == 0) {
            str[i] += 32;
        } else if (str[i] == ' ' || str[i] == '-' || str[i] == '+') {
            begining_of_word = 1;
        } else {
            begining_of_word = 0;
        }
    }
    return str;
}