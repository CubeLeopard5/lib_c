int my_int_array_sum(int *tab, int size)
{
    int count = 0;

    for (int i = 0; i < size; i++) {
        count = count + tab[i];
    }
    return count;
}