int my_compute_power(int nb, int p)
{
    if (p != 0)
        return nb * my_compute_power(nb, p - 1);
    else
        return 1;
}