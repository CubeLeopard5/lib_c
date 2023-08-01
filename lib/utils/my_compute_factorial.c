int my_compute_factorial(int nb)
{
    if (nb == 0) {
        return 1;
    } else if (nb < 0) {
        return 0;
    } else {
        return nb * my_compute_factorial(nb - 1);
    }
}