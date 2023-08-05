union ColorUnion {
    int color;
    unsigned char bytes[4];
};

int swap_endian_color(int color) {
    union ColorUnion colorUnion;
    unsigned char temp = 0;

    colorUnion.color = color;
    temp = colorUnion.bytes[0];
    colorUnion.bytes[0] = colorUnion.bytes[3];
    colorUnion.bytes[3] = temp;
    temp = colorUnion.bytes[1];
    colorUnion.bytes[1] = colorUnion.bytes[2];
    colorUnion.bytes[2] = temp;
    return colorUnion.color;
}