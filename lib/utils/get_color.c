int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int color = 0;

    color = color | (red << 16);
    color = color | (green << 8);
    color = color | blue;
    return color;
}