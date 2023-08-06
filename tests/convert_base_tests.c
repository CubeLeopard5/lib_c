#include <criterion/criterion.h>
#include "../lib/utils/my.h"

Test(convert_base, binary_to_decimal)
{
    const char *binary = "10101";
    const char *base_from = "01";
    const char *base_to = "0123456789";
    char *result = convert_base(binary, base_from, base_to);
    cr_assert_str_eq(result, "21", "Expected: %s, Got: %s", "21", result);
    free(result);
}

Test(convert_base, decimal_to_binary)
{
    const char *decimal = "17";
    const char *base_from = "0123456789";
    const char *base_to = "01";
    char *result = convert_base(decimal, base_from, base_to);
    cr_assert_str_eq(result, "10001", "Expected: %s, Got: %s", "10001", result);
    free(result);
}

Test(convert_base, hex_to_binary)
{
    const char *hexadecimal = "1A3F";
    const char *base_from = "0123456789ABCDEF";
    const char *base_to = "01";
    char *result = convert_base(hexadecimal, base_from, base_to);
    cr_assert_str_eq(result, "1101000111111", "Expected: %s, Got: %s", "1101000111111", result);
    free(result);
}

Test(convert_base, binary_to_hex)
{
    const char *binary = "1101000111111";
    const char *base_from = "01";
    const char *base_to = "0123456789ABCDEF";
    char *result = convert_base(binary, base_from, base_to);
    cr_assert_str_eq(result, "1A3F", "Expected: %s, Got: %s", "1A3F", result);
    free(result);
}

Test(convert_base, hex_to_octal)
{
    const char *hexadecimal = "3F";
    const char *base_from = "0123456789ABCDEF";
    const char *base_to = "01234567";
    char *result = convert_base(hexadecimal, base_from, base_to);
    cr_assert_str_eq(result, "77", "Expected: %s, Got: %s", "77", result);
    free(result);
}