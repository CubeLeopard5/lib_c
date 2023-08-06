#include <criterion/criterion.h>
#include "../lib/utils/my.h"

Test(my_revstr_tests_tests, simple_str) {
    cr_assert_str_eq(my_revstr("a"), "a");
    cr_assert_str_eq(my_revstr("ab"), "ba");
    cr_assert_str_eq(my_revstr("abc"), "cba");
    cr_assert_str_eq(my_revstr("23456"), "65432");
}

Test(my_revstr_tests_tests, empty_string) {
    cr_assert_str_eq(my_revstr(""), "");
    cr_assert_str_eq(my_revstr(" "), " ");
}