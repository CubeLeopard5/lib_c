#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_isneg(int n);
int my_print_comb(void);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *array, int size);
int my_compute_factorial(int nb);
int my_compute_power(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strcasestr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_putnbr_base(int nbr, char const *base);
int my_getnbr_base(char const *str, char const *base);
char *my_strchr(const char *str, char c);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str, char const c);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
int get_color(unsigned char red, unsigned char green, unsigned char blue);
int swap_endian_color(int color);
int my_sort_word_array(char **tab);
int my_advanced_sort_word_array(char **tab, int (*cmp)(char const *, char const *));
int my_int_array_sum(int *tab, int size);
int my_get_word_array_len(char const **tab);
char *my_word_array_to_str(char **tab, char c);
char **my_word_array_dup(char **src);

#endif