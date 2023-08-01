int my_compute_square_root(int nb)
{
    int counter = 0;

    for (int sub = 1; nb > 0; sub += 2, counter++) {
        nb = nb - sub;
    }
    if (nb == 0) {
        return counter;
    }
    return 0;
}