#include <criterion/criterion.h>
#include "../lib/utils/my.h"

Test(my_getnbr, valid_positive_input)
{
    const char *str = "12345";
    int result = my_getnbr(str);
    cr_assert_eq(result, 12345, "Expected: %d, Got: %d", 12345, result);
}

Test(my_getnbr, valid_negative_input)
{
    const char *str = "-6789";
    int result = my_getnbr(str);
    cr_assert_eq(result, -6789, "Expected: %d, Got: %d", -6789, result);
}

Test(my_getnbr, invalid_input_with_non_digit)
{
    const char *str = "123abc";
    int result = my_getnbr(str);
    cr_assert_eq(result, 123, "Expected: %d, Got: %d", 123, result);
}

Test(my_getnbr, valid_input_with_leading_zeros)
{
    const char *str = "000456";
    int result = my_getnbr(str);
    cr_assert_eq(result, 456, "Expected: %d, Got: %d", 456, result);
}

Test(my_getnbr, invalid_input_with_multiple_signs)
{
    const char *str = "--789";
    int result = my_getnbr(str);
    cr_assert_eq(result, -789, "Expected: %d, Got: %d", -789, result);
}

Test(my_getnbr, empty_string_input)
{
    const char *str = "";
    int result = my_getnbr(str);
    cr_assert_eq(result, 0, "Expected: %d, Got: %d", 0, result);
}
