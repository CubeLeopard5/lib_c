#include <unistd.h>

/*
Write the given character
*/
void my_putchar(char c)
{
    write(1, &c, 1);
}