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

#endif