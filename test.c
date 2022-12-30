#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(sscanf_test_char) {
    char *test = "s";
    char ch1, ch2;
    int res1 = sscanf(test, "%c", &ch1);
    int res2 = s21_sscanf(test, "%c", &ch2);
    ck_assert_int_eq(ch1, ch2);
    char *test1 = "tring";
    res1 = sscanf(test1, "%c", &ch1);
    res2 = s21_sscanf(test1, "%c", &ch2);
    ck_assert_int_eq(ch1, ch2);
    char *test2 = "ring";
    res1 = sscanf(test2, "%1c", &ch1);
    res2 = s21_sscanf(test2, "%1c", &ch2);
    ck_assert_int_eq(ch1, ch2);
}
END_TEST

START_TEST(sscanf_test_string) {
    char ress1[20], ress2[20];
    char *test = "string ";
    int res1 = sscanf(test, "%s", ress1);
    int res2 = s21_sscanf(test, "%s", ress2);
    ck_assert_str_eq(ress1, ress2);
    char *test1 = "str ing";
    res1 = sscanf(test1, "%10s", ress1);
    res2 = s21_sscanf(test1, "%10s", ress2);
    ck_assert_str_eq(ress1, ress2);
    char *test2 = "12str123''.";
    res1 = sscanf(test2, "%9s", ress1);
    res2 = s21_sscanf(test2, "%9s", ress2);
    ck_assert_str_eq(ress1, ress2);
    char *test3 = "ssssssssssssssssssssssssssssssssssssssss";
    res1 = sscanf(test3, "%21s", ress1);
    res2 = s21_sscanf(test3, "%21s", ress2);
    ck_assert_str_eq(ress1, ress2);
}
END_TEST


START_TEST(sscanf_test_int) {
    char *test = "12345";
    int d1, d2;
    int res1 = sscanf(test, "%d", &d1);
    int res2 = s21_sscanf(test, "%d", &d2);
    ck_assert_int_eq(d1, d2);
    char *test1 = "-12345";
    res1 = sscanf(test1, "%4d", &d1);
    res2 = s21_sscanf(test1, "%4d", &d2);
    ck_assert_int_eq(d2, d2);
    char *test2 = "+9999999999999999";
    res1 = sscanf(test2, "%d", &d1);
    res2 = s21_sscanf(test2, "%d", &d2);
    ck_assert_int_eq(d1, d2);
    char *test3 = "+12.15";
    res1 = sscanf(test3, "%5d", &d1);
    res2 = s21_sscanf(test3, "%5d", &d2);
    ck_assert_int_eq(d1, d2);

    long int ld1, ld2;
    int res3 = sscanf(test, "%ld", &ld1);
    int res4 = s21_sscanf(test, "%ld", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test35 = "-12345";
    res3 = sscanf(test35, "%4ld", &ld1);
    res4 = s21_sscanf(test35, "%4ld", &ld2);
    ck_assert_int_eq(ld2, ld2);
    char *test4 = "+999999999999999999999999";
    res3 = sscanf(test4, "%ld", &ld1);
    res4 = s21_sscanf(test4, "%ld", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test5 = "+12.15";
    res3 = sscanf(test5, "%5ld", &ld1);
    res4 = s21_sscanf(test5, "%5ld", &ld2);
    ck_assert_int_eq(ld1, ld2);
    short int hd1, hd2;
    int res5 = sscanf(test, "%hd", &hd1);
    int res6 = s21_sscanf(test, "%hd", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test6 = "-12345";
    res5 = sscanf(test6, "%4hd", &hd1);
    res6 = s21_sscanf(test6, "%4hd", &hd2);
    ck_assert_int_eq(hd2, hd2);
    char *test7 = "+9999999999999999";
    res5 = sscanf(test7, "%hd", &hd1);
    res6 = s21_sscanf(test7, "%hd", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test8 = "+12.15";
    res5 = sscanf(test8, "%5hd", &hd1);
    res6 = s21_sscanf(test8, "%5hd", &hd2);
    ck_assert_int_eq(hd1, hd2);
}
END_TEST

START_TEST(sscanf_test_uint) {
     char *test = "0x123FF";
    unsigned int d1, d2;
    int res1 = sscanf(test, "%u", &d1);
    int res2 = s21_sscanf(test, "%u", &d2);
    ck_assert_int_eq(d1, d2);
    char *test1 = "-12345";
    res1 = sscanf(test1, "%4u", &d1);
    res2 = s21_sscanf(test1, "%4u", &d2);
    ck_assert_int_eq(d2, d2);
    char *test2 = "+9999999999999999";
    res1 = sscanf(test2, "%u", &d1);
    res2 = s21_sscanf(test2, "%u", &d2);
    ck_assert_int_eq(d1, d2);
    char *test3 = "-12.15";
    res1 = sscanf(test3, "%5u", &d1);
    res2 = s21_sscanf(test3, "%5u", &d2);
    ck_assert_int_eq(d1, d2);
    long unsigned int ld1, ld2;
    int res3 = sscanf(test, "%1lu", &ld1);
    int res4 = s21_sscanf(test, "%1lu", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test35 = "-12345";
    res3 = sscanf(test35, "%4lu", &ld1);
    res4 = s21_sscanf(test35, "%4lu", &ld2);
    ck_assert_int_eq(ld2, ld2);
    char *test4 = "+999999999999999999999999";
    res3 = sscanf(test4, "%lu", &ld1);
    res4 = s21_sscanf(test4, "%lu", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test5 = "+12.15";
    res3 = sscanf(test5, "%5lu", &ld1);
    res4 = s21_sscanf(test5, "%5lu", &ld2);
    ck_assert_int_eq(ld1, ld2);

    char *test11 = "0x123FFffffffffffffffffffffff";
    res3 = sscanf(test11, "%lu", &ld1);
    res4 = s21_sscanf(test11, "%lu", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test13 = "-0xABCF";
    res3 = sscanf(test13, "%4lu", &ld1);
    res4 = s21_sscanf(test13, "%4lu", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test12 = "-12345";
    res3 = sscanf(test12, "%4lu", &ld1);
    res4 = s21_sscanf(test12, "%4lu", &ld2);
    ck_assert_int_eq(ld2, ld2);
    char *test9 = "+999999999999999999999999";
    res3 = sscanf(test9, "%lu", &ld1);
    res4 = s21_sscanf(test9, "%lu", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test10 = "+12.15";
    res3 = sscanf(test10, "%5lu", &ld1);
    res4 = s21_sscanf(test10, "%5lu", &ld2);
    ck_assert_int_eq(ld1, ld2);
    short unsigned int hd1, hd2;
    int res5 = sscanf(test, "%hu", &hd1);
    int res6 = s21_sscanf(test, "%hu", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test6 = "-12345";
    res5 = sscanf(test6, "%4hu", &hd1);
    res6 = s21_sscanf(test6, "%4hu", &hd2);
    ck_assert_int_eq(hd2, hd2);
    char *test7 = "+9999999999999999";
    res5 = sscanf(test7, "%hu", &hd1);
    res6 = s21_sscanf(test7, "%hu", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test8 = "+12.15";
    res5 = sscanf(test8, "%5hu", &hd1);
    res6 = s21_sscanf(test8, "%5hu", &hd2);
    ck_assert_int_eq(hd1, hd2);
}
END_TEST

START_TEST(sscanf_test_oint) {
    char *test = "0x123FF";
    unsigned int d1, d2;
    int res1 = sscanf(test, "%o", &d1);
    int res2 = s21_sscanf(test, "%o", &d2);
    ck_assert_int_eq(d1, d2);
    char *test1 = "-12345";
    res1 = sscanf(test1, "%4o", &d1);
    res2 = s21_sscanf(test1, "%4o", &d2);
    ck_assert_int_eq(d2, d2);
    char *test2 = "+9";
    res1 = sscanf(test2, "%o", &d1);
    res2 = s21_sscanf(test2, "%o", &d2);
    ck_assert_int_eq(d1, d2);
    char *test3 = "-12.15";
    res1 = sscanf(test3, "%5o", &d1);
    res2 = s21_sscanf(test3, "%5o", &d2);
    ck_assert_int_eq(d1, d2);

    long unsigned int ld1, ld2;
    int res3 = sscanf(test, "%1lo", &ld1);
    int res4 = s21_sscanf(test, "%1lo", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test35 = "-12345";
    res3 = sscanf(test35, "%4lo", &ld1);
    res4 = s21_sscanf(test35, "%4lo", &ld2);
    ck_assert_int_eq(ld2, ld2);
    char *test4 = "+999999999999999999999999";
    res3 = sscanf(test4, "%lo", &ld1);
    res4 = s21_sscanf(test4, "%lo", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test5 = "+12.15";
    res3 = sscanf(test5, "%5lo", &ld1);
    res4 = s21_sscanf(test5, "%5lo", &ld2);
    ck_assert_int_eq(ld1, ld2);

    char *test11 = "0x123FFffffffffffffffffffffff";
    res3 = sscanf(test11, "%lo", &ld1);
    res4 = s21_sscanf(test11, "%lo", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test13 = "-0xABCF";
    res3 = sscanf(test13, "%4lo", &ld1);
    res4 = s21_sscanf(test13, "%4lo", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test12 = "-12345";
    res3 = sscanf(test12, "%4lo", &ld1);
    res4 = s21_sscanf(test12, "%4lo", &ld2);
    ck_assert_int_eq(ld2, ld2);
    char *test9 = "+999999999999999999999999";
    res3 = sscanf(test9, "%lo", &ld1);
    res4 = s21_sscanf(test9, "%lo", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test10 = "+12.15";
    res3 = sscanf(test10, "%5lo", &ld1);
    res4 = s21_sscanf(test10, "%5lo", &ld2);
    ck_assert_int_eq(ld1, ld2);
    short unsigned int hd1, hd2;
    int res5 = sscanf(test, "%ho", &hd1);
    int res6 = s21_sscanf(test, "%ho", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test6 = "-12345";
    res5 = sscanf(test6, "%4ho", &hd1);
    res6 = s21_sscanf(test6, "%4ho", &hd2);
    ck_assert_int_eq(hd2, hd2);
    char *test7 = "+9999999999999999";
    res5 = sscanf(test7, "%ho", &hd1);
    res6 = s21_sscanf(test7, "%ho", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test8 = "+12.15";
    res5 = sscanf(test8, "%5ho", &hd1);
    res6 = s21_sscanf(test8, "%5ho", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test15 = "23.23";
    res5 = sscanf(test8, "%*o");
    res6 = s21_sscanf(test8, "%*o");
    ck_assert_int_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
}
END_TEST

START_TEST(sscanf_test_xint) {
    char *test = "0x123FF";
    unsigned int d1, d2;
    int res1 = sscanf(test, "%x", &d1);
    int res2 = s21_sscanf(test, "%x", &d2);
    ck_assert_int_eq(d1, d2);
    char *test1 = "-12345";
    res1 = sscanf(test1, "%4x", &d1);
    res2 = s21_sscanf(test1, "%4x", &d2);
    ck_assert_int_eq(d2, d2);
    char *test2 = "TTY";
    res1 = sscanf(test2, "%x", &d1);
    res2 = s21_sscanf(test2, "%x", &d2);
    ck_assert_int_eq(d1, d2);
    char *test3 = "-12.15";
    res1 = sscanf(test3, "%5x", &d1);
    res2 = s21_sscanf(test3, "%5x", &d2);
    ck_assert_int_eq(d1, d2);

    long unsigned int ld1, ld2;
    int res3 = sscanf(test, "%1lx", &ld1);
    int res4 = s21_sscanf(test, "%1lx", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test35 = "-12345";
    res3 = sscanf(test35, "%4lx", &ld1);
    res4 = s21_sscanf(test35, "%4lx", &ld2);
    ck_assert_int_eq(ld2, ld2);
    char *test4 = "+999999999999999999999999";
    res3 = sscanf(test4, "%lx", &ld1);
    res4 = s21_sscanf(test4, "%lx", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test5 = "+12.15";
    res3 = sscanf(test5, "%5lx", &ld1);
    res4 = s21_sscanf(test5, "%5lx", &ld2);
    ck_assert_int_eq(ld1, ld2);

    char *test11 = "0x123FFffffffffffffffffffffff";
    res3 = sscanf(test11, "%lx", &ld1);
    res4 = s21_sscanf(test11, "%lx", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test13 = "-0xABCF";
    res3 = sscanf(test13, "%4lx", &ld1);
    res4 = s21_sscanf(test13, "%4lx", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test12 = "-12345ABC";
    res3 = sscanf(test12, "%4lx", &ld1);
    res4 = s21_sscanf(test12, "%4lx", &ld2);
    ck_assert_int_eq(ld2, ld2);
    char *test9 = "+999999999999999999999999Ee";
    res3 = sscanf(test9, "%lx", &ld1);
    res4 = s21_sscanf(test9, "%lx", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test10 = "+12.15";
    res3 = sscanf(test10, "%5lx", &ld1);
    res4 = s21_sscanf(test10, "%5lx", &ld2);
    ck_assert_int_eq(ld1, ld2);
    short unsigned int hd1, hd2;
    int res5 = sscanf(test, "%hx", &hd1);
    int res6 = s21_sscanf(test, "%hx", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test6 = "-12345";
    res5 = sscanf(test6, "%4hx", &hd1);
    res6 = s21_sscanf(test6, "%4hx", &hd2);
    ck_assert_int_eq(hd2, hd2);
    char *test7 = "-0x45AbE1";
    res5 = sscanf(test7, "%hx", &hd1);
    res6 = s21_sscanf(test7, "%hx", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test8 = "+12C2.15E";
    res5 = sscanf(test8, "%5hx", &hd1);
    res6 = s21_sscanf(test8, "%5hx", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test15 = "23.23";
    res5 = sscanf(test8, "%*x");
    res6 = s21_sscanf(test15, "%*x");
    ck_assert_int_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
    char *test20 = "-0XFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
    res5 = sscanf(test20, "%x", &d1);
    res6 = s21_sscanf(test20, "%x", &d2);
    ck_assert_int_eq(d1, d2);
    ck_assert_int_eq(res5, res6);
}
END_TEST


START_TEST(sscanf_test_Xint) {
    char *test = "0x123FF";
    unsigned int d1, d2;
    int res1 = sscanf(test, "%X", &d1);
    int res2 = s21_sscanf(test, "%X", &d2);
    ck_assert_int_eq(d1, d2);
    char *test1 = "-12345";
    res1 = sscanf(test1, "%4X", &d1);
    res2 = s21_sscanf(test1, "%4X", &d2);
    ck_assert_int_eq(d2, d2);
    char *test2 = "TTY";
    res1 = sscanf(test2, "%X", &d1);
    res2 = s21_sscanf(test2, "%X", &d2);
    ck_assert_int_eq(d1, d2);
    char *test3 = "-12.15";
    res1 = sscanf(test3, "%5X", &d1);
    res2 = s21_sscanf(test3, "%5X", &d2);
    ck_assert_int_eq(d1, d2);
    long unsigned int ld1, ld2;
    int res3 = sscanf(test, "%1lX", &ld1);
    int res4 = s21_sscanf(test, "%1lX", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test35 = "-12345";
    res3 = sscanf(test35, "%4lX", &ld1);
    res4 = s21_sscanf(test35, "%4lX", &ld2);
    ck_assert_int_eq(ld2, ld2);
    char *test4 = "+999999999999999999999999";
    res3 = sscanf(test4, "%lX", &ld1);
    res4 = s21_sscanf(test4, "%lX", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test5 = "+12.15";
    res3 = sscanf(test5, "%5lX", &ld1);
    res4 = s21_sscanf(test5, "%5lX", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test11 = "0x123FFffffffffffffffffffffff";
    res3 = sscanf(test11, "%lX", &ld1);
    res4 = s21_sscanf(test11, "%lX", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test13 = "-0xABCF";
    res3 = sscanf(test13, "%4lX", &ld1);
    res4 = s21_sscanf(test13, "%4lX", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test12 = "-12345ABC";
    res3 = sscanf(test12, "%4lX", &ld1);
    res4 = s21_sscanf(test12, "%4lX", &ld2);
    ck_assert_int_eq(ld2, ld2);
    char *test9 = "+999999999999999999999999Ee";
    res3 = sscanf(test9, "%lX", &ld1);
    res4 = s21_sscanf(test9, "%lX", &ld2);
    ck_assert_int_eq(ld1, ld2);
    char *test10 = "+12.15";
    res3 = sscanf(test10, "%5lX", &ld1);
    res4 = s21_sscanf(test10, "%5lX", &ld2);
    ck_assert_int_eq(ld1, ld2);
    short unsigned int hd1, hd2;
    int res5 = sscanf(test, "%hX", &hd1);
    int res6 = s21_sscanf(test, "%hX", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test6 = "-12345";
    res5 = sscanf(test6, "%4hX", &hd1);
    res6 = s21_sscanf(test6, "%4hX", &hd2);
    ck_assert_int_eq(hd2, hd2);
    char *test7 = "-0x45AbE1";
    res5 = sscanf(test7, "%hX", &hd1);
    res6 = s21_sscanf(test7, "%hX", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test8 = "+12C2.15E";
    res5 = sscanf(test8, "%5hX", &hd1);
    res6 = s21_sscanf(test8, "%5hX", &hd2);
    ck_assert_int_eq(hd1, hd2);
    char *test15 = "23.23";
    res5 = sscanf(test8, "%*X");
    res6 = s21_sscanf(test15, "%*X");
    ck_assert_int_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
    char *test20 = "-0xfffffffffffffffffffffffffffffffffffffffff";
    res5 = sscanf(test20, "%X", &d1);
    res6 = s21_sscanf(test20, "%X", &d2);
    ck_assert_int_eq(d1, d2);
    ck_assert_int_eq(res5, res6);
}
END_TEST


START_TEST(sscanf_test_pointer) {
    char *test = "0x123FF";
    void* d1, *d2;
    int res1 = sscanf(test, "%p", &d1);
    int res2 = s21_sscanf(test, "%p", &d2);
    ck_assert_ptr_eq(d1, d2);
    char *test1 = "-12345";
    res1 = sscanf(test1, "%4p", &d1);
    res2 = s21_sscanf(test1, "%4p", &d2);
    ck_assert_ptr_eq(d2, d2);
    char *test2 = "TTY";
    res1 = sscanf(test2, "%p", &d1);
    res2 = s21_sscanf(test2, "%p", &d2);
    ck_assert_ptr_eq(d1, d2);
    char *test3 = "-12.15";
    res1 = sscanf(test3, "%5p", &d1);
    res2 = s21_sscanf(test3, "%5p", &d2);
    ck_assert_ptr_eq(d1, d2);
    void *ld1, *ld2;
    int res3 = sscanf(test, "%1p", &ld1);
    int res4 = s21_sscanf(test, "%1p", &ld2);
    ck_assert_ptr_eq(ld1, ld2);
    char *test35 = "-12345";
    res3 = sscanf(test35, "%4p", &ld1);
    res4 = s21_sscanf(test35, "%4p", &ld2);
    ck_assert_ptr_eq(ld2, ld2);
    char *test4 = "+999999999999999999999999";
    res3 = sscanf(test4, "%p", &ld1);
    res4 = s21_sscanf(test4, "%p", &ld2);
    ck_assert_ptr_eq(ld1, ld2);
    char *test5 = "+12.15";
    res3 = sscanf(test5, "%5p", &ld1);
    res4 = s21_sscanf(test5, "%5p", &ld2);
    ck_assert_ptr_eq(ld1, ld2);
    char *test11 = "0x123FFffffffffffffffffffffff";
    res3 = sscanf(test11, "%p", &ld1);
    res4 = s21_sscanf(test11, "%p", &ld2);
    ck_assert_ptr_eq(ld1, ld2);
    char *test13 = "-0xABCF";
    res3 = sscanf(test13, "%4p", &ld1);
    res4 = s21_sscanf(test13, "%4p", &ld2);
    ck_assert_ptr_eq(ld1, ld2);
    char *test12 = "-12345ABC";
    res3 = sscanf(test12, "%4p", &ld1);
    res4 = s21_sscanf(test12, "%4p", &ld2);
    ck_assert_ptr_eq(ld2, ld2);
    char *test9 = "+999999999999999999999999Ee";
    res3 = sscanf(test9, "%p", &ld1);
    res4 = s21_sscanf(test9, "%p", &ld2);
    ck_assert_ptr_eq(ld1, ld2);
    char *test10 = "+12.15";
    res3 = sscanf(test10, "%5p", &ld1);
    res4 = s21_sscanf(test10, "%5p", &ld2);
    ck_assert_ptr_eq(ld1, ld2);
    void* hd1, *hd2;
    int res5 = sscanf(test, "%p", &hd1);
    int res6 = s21_sscanf(test, "%p", &hd2);
    ck_assert_ptr_eq(hd1, hd2);
    char *test6 = "-12345";
    res5 = sscanf(test6, "%4p", &hd1);
    res6 = s21_sscanf(test6, "%4p", &hd2);
    ck_assert_ptr_eq(hd2, hd2);
    char *test7 = "-0x45AbE1";
    res5 = sscanf(test7, "%p", &hd1);
    res6 = s21_sscanf(test7, "%p", &hd2);
    ck_assert_ptr_eq(hd1, hd2);
    char *test8 = "+12C2.15E";
    res5 = sscanf(test8, "%5p", &hd1);
    res6 = s21_sscanf(test8, "%5p", &hd2);
    ck_assert_ptr_eq(hd1, hd2);
    char *test15 = "23.23";
    res5 = sscanf(test8, "%*p");
    res6 = s21_sscanf(test15, "%*p");
    ck_assert_ptr_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
    char *test20 = "-0xfffffffffffffffffffffffffffffffffffffffff";
    res5 = sscanf(test20, "%p", &d1);
    res6 = s21_sscanf(test20, "%p", &d2);
    ck_assert_ptr_eq(d1, d2);
    ck_assert_int_eq(res5, res6);
    char *test21 = "0xABCFDef1111111111111111111111111111111111111";
    res5 = sscanf(test21, "%p", &d1);
    res6 = s21_sscanf(test21, "%p", &d2);
    ck_assert_ptr_eq(d1, d2);
    ck_assert_int_eq(res5, res6);
}
END_TEST


START_TEST(sscanf_test_floatf) {
    char *test = "123.456";
    float d1, d2;
    int res1 = sscanf(test, "%f", &d1);
    int res2 = s21_sscanf(test, "%f", &d2);
    ck_assert_float_eq(d1, d2);
    char *test1 = "-12345.12345678";
    res1 = sscanf(test1, "%4f", &d1);
    res2 = s21_sscanf(test1, "%4f", &d2);
    ck_assert_float_eq(d2, d2);
    char *test2 = "TTY";
    res1 = sscanf(test2, "%f", &d1);
    res2 = s21_sscanf(test2, "%f", &d2);
    ck_assert_double_eq(d1, d2);
    char *test3 = "-12.15";
    res1 = sscanf(test3, "%5f", &d1);
    res2 = s21_sscanf(test3, "%5f", &d2);
    ck_assert_double_eq(d1, d2);
    double ld1, ld2;
    int res3 = sscanf(test, "%1lf", &ld1);
    int res4 = s21_sscanf(test, "%1lf", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test35 = "-12345";
    res3 = sscanf(test35, "%4lf", &ld1);
    res4 = s21_sscanf(test35, "%4lf", &ld2);
    ck_assert_double_eq(ld2, ld2);
    char *test4 = "+999999999999999999999999";
    res3 = sscanf(test4, "%lf", &ld1);
    res4 = s21_sscanf(test4, "%lf", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test5 = "+12.15";
    res3 = sscanf(test5, "%5lf", &ld1);
    res4 = s21_sscanf(test5, "%5lf", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test11 = "-5. 1";
    res3 = sscanf(test11, "%lf", &ld1);
    res4 = s21_sscanf(test11, "%lf", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test13 = "-0";
    res3 = sscanf(test13, "%4lf", &ld1);
    res4 = s21_sscanf(test13, "%4lf", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test12 = "1E-2";
    res3 = sscanf(test12, "%4lf", &ld1);
    res4 = s21_sscanf(test12, "%4lf", &ld2);
    ck_assert_double_eq(ld2, ld2);
    char *test9 = "+999999999999999999999999Ee";
    res3 = sscanf(test9, "%lf", &ld1);
    res4 = s21_sscanf(test9, "%lf", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test10 = "+12.E-3";
    res3 = sscanf(test10, "%5lf", &ld1);
    res4 = s21_sscanf(test10, "%5lf", &ld2);
    ck_assert_double_eq(ld1, ld2);
    long double hd1, hd2;
    int res5 = sscanf(test, "%Lf", &hd1);
    int res6 = s21_sscanf(test, "%Lf", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test6 = "-12345";
    res5 = sscanf(test6, "%4Lf", &hd1);
    res6 = s21_sscanf(test6, "%4Lf", &hd2);
    ck_assert_ldouble_eq(hd2, hd2);
    char *test7 = "1E0";
    res5 = sscanf(test7, "%Lf", &hd1);
    res6 = s21_sscanf(test7, "%Lf", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test8 = "1ge";
    res5 = sscanf(test8, "%5Lf", &hd1);
    res6 = s21_sscanf(test8, "%5Lf", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test15 = "23.23";
    res5 = sscanf(test8, "%*f");
    res6 = s21_sscanf(test15, "%*Lf");
    ck_assert_ldouble_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
    char *test20 = "+55555.555555555555555";
    res5 = sscanf(test20, "%Lf", &hd1);
    res6 = s21_sscanf(test20, "%Lf", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
}
END_TEST

START_TEST(sscanf_test_floate) {
    char *test = "123.456";
    float d1, d2;
    int res1 = sscanf(test, "%e", &d1);
    int res2 = s21_sscanf(test, "%e", &d2);
    ck_assert_float_eq(d1, d2);
    char *test1 = "-12345.12345678";
    res1 = sscanf(test1, "%4e", &d1);
    res2 = s21_sscanf(test1, "%4e", &d2);
    ck_assert_float_eq(d2, d2);
    char *test2 = "TTY";
    res1 = sscanf(test2, "%e", &d1);
    res2 = s21_sscanf(test2, "%e", &d2);
    ck_assert_double_eq(d1, d2);
    char *test3 = "-12.15";
    res1 = sscanf(test3, "%5e", &d1);
    res2 = s21_sscanf(test3, "%5e", &d2);
    ck_assert_double_eq(d1, d2);
    double ld1, ld2;
    int res3 = sscanf(test, "%1le", &ld1);
    int res4 = s21_sscanf(test, "%1le", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test35 = "-12345E-2";
    res3 = sscanf(test35, "%4le", &ld1);
    res4 = s21_sscanf(test35, "%4le", &ld2);
    ck_assert_double_eq(ld2, ld2);
    char *test4 = "+1235.E-2";
    res3 = sscanf(test4, "%le", &ld1);
    res4 = s21_sscanf(test4, "%le", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test5 = "+12.15";
    res3 = sscanf(test5, "%5le", &ld1);
    res4 = s21_sscanf(test5, "%5le", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test11 = "-5. 1";
    res3 = sscanf(test11, "%le", &ld1);
    res4 = s21_sscanf(test11, "%le", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test13 = "-0";
    res3 = sscanf(test13, "%4le", &ld1);
    res4 = s21_sscanf(test13, "%4le", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test12 = "123E-2";
    res3 = sscanf(test12, "%4le", &ld1);
    res4 = s21_sscanf(test12, "%4le", &ld2);
    ck_assert_double_eq(ld2, ld2);
    char *test9 = "+999999999999999999999999Ee";
    res3 = sscanf(test9, "%le", &ld1);
    res4 = s21_sscanf(test9, "%le", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test10 = "+12.e-3";
    res3 = sscanf(test10, "%5le", &ld1);
    res4 = s21_sscanf(test10, "%5le", &ld2);
    ck_assert_double_eq(ld1, ld2);
    long double hd1, hd2;
    int res5 = sscanf(test, "%Le", &hd1);
    int res6 = s21_sscanf(test, "%Le", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test6 = "-12345e+1";
    res5 = sscanf(test6, "%4Le", &hd1);
    res6 = s21_sscanf(test6, "%4Le", &hd2);
    ck_assert_ldouble_eq(hd2, hd2);
    char *test7 = "1e5";
    res5 = sscanf(test7, "%Le", &hd1);
    res6 = s21_sscanf(test7, "%Le", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test8 = "1e";
    res5 = sscanf(test8, "%5Le", &hd1);
    res6 = s21_sscanf(test8, "%5Le", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test15 = "23.23";
    res5 = sscanf(test8, "%*e");
    res6 = s21_sscanf(test15, "%*Le");
    ck_assert_ldouble_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
    char *test20 = "+55555.555555555555555";
    res5 = sscanf(test20, "%Le", &hd1);
    res6 = s21_sscanf(test20, "%Le", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
}
END_TEST

START_TEST(sscanf_test_floatg) {
    char *test = "123.456";
    float d1, d2;
    int res1 = sscanf(test, "%g", &d1);
    int res2 = s21_sscanf(test, "%g", &d2);
    ck_assert_float_eq(d1, d2);
    char *test1 = "-12345.12345678";
    res1 = sscanf(test1, "%4G", &d1);
    res2 = s21_sscanf(test1, "%4G", &d2);
    ck_assert_float_eq(d2, d2);
    char *test2 = "TTY";
    res1 = sscanf(test2, "%g", &d1);
    res2 = s21_sscanf(test2, "%g", &d2);
    ck_assert_double_eq(d1, d2);
    char *test3 = "-12.15";
    res1 = sscanf(test3, "%5G", &d1);
    res2 = s21_sscanf(test3, "%5G", &d2);
    ck_assert_double_eq(d1, d2);
    double ld1, ld2;
    int res3 = sscanf(test, "%1lG", &ld1);
    int res4 = s21_sscanf(test, "%1lG", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test35 = "-12345E-2";
    res3 = sscanf(test35, "%4lg", &ld1);
    res4 = s21_sscanf(test35, "%4lg", &ld2);
    ck_assert_double_eq(ld2, ld2);
    char *test4 = "+1235.E-2";
    res3 = sscanf(test4, "%lG", &ld1);
    res4 = s21_sscanf(test4, "%lG", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test5 = "+12.15";
    res3 = sscanf(test5, "%5lg", &ld1);
    res4 = s21_sscanf(test5, "%5lg", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test11 = "-5. 1";
    res3 = sscanf(test11, "%lg", &ld1);
    res4 = s21_sscanf(test11, "%lg", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test13 = "-0";
    res3 = sscanf(test13, "%4lG", &ld1);
    res4 = s21_sscanf(test13, "%4lG", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test12 = "123E-2";
    res3 = sscanf(test12, "%4lg", &ld1);
    res4 = s21_sscanf(test12, "%4lg", &ld2);
    ck_assert_double_eq(ld2, ld2);
    char *test9 = "+999999999999999999999999Ee";
    res3 = sscanf(test9, "%lG", &ld1);
    res4 = s21_sscanf(test9, "%lG", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test10 = "+12.e-3";
    res3 = sscanf(test10, "%5lg", &ld1);
    res4 = s21_sscanf(test10, "%5lg", &ld2);
    ck_assert_double_eq(ld1, ld2);
    long double hd1, hd2;
    int res5 = sscanf(test, "%LG", &hd1);
    int res6 = s21_sscanf(test, "%LG", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test6 = "-12345e+1";
    res5 = sscanf(test6, "%4Lg", &hd1);
    res6 = s21_sscanf(test6, "%4Lg", &hd2);
    ck_assert_ldouble_eq(hd2, hd2);
    char *test7 = "1e5";
    res5 = sscanf(test7, "%Lg", &hd1);
    res6 = s21_sscanf(test7, "%Lg", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test8 = "1e";
    res5 = sscanf(test8, "%5Lg", &hd1);
    res6 = s21_sscanf(test8, "%5Lg", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test15 = "23.23";
    res5 = sscanf(test8, "%*G");
    res6 = s21_sscanf(test15, "%*LG");
    ck_assert_ldouble_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
    char *test20 = "+55555.555555555555555";
    res5 = sscanf(test20, "%LG", &hd1);
    res6 = s21_sscanf(test20, "%LG", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
    char *test21 = "+55555.555555555555555";
    res5 = sscanf(test21, "%40LG", &hd1);
    res6 = s21_sscanf(test21, "%40LG", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
}
END_TEST


START_TEST(sscanf_test_proc) {
    char *test = "% 123.456";
    float d1, d2;
    int res1 = sscanf(test, "%%%g", &d1);
    int res2 = s21_sscanf(test, "%%%g", &d2);
    ck_assert_float_eq(d1, d2);
    char *test1 = "%-12345.12345678";
    res1 = sscanf(test1, "%%%4G", &d1);
    res2 = s21_sscanf(test1, "%%%4G", &d2);
    ck_assert_float_eq(d2, d2);
    char *test2 = "%TTY";
    res1 = sscanf(test2, "%%%g", &d1);
    res2 = s21_sscanf(test2, "%%%g", &d2);
    ck_assert_double_eq(d1, d2);
    char *test3 = "%-12.15";
    res1 = sscanf(test3, "%%%5G", &d1);
    res2 = s21_sscanf(test3, "%%%5G", &d2);
    ck_assert_double_eq(d1, d2);
    double ld1, ld2;
    int res3 = sscanf(test, "%%%1lG", &ld1);
    int res4 = s21_sscanf(test, "%%%1lG", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test35 = "%-12345E-2";
    res3 = sscanf(test35, "%%%4lg", &ld1);
    res4 = s21_sscanf(test35, "%%%4lg", &ld2);
    ck_assert_double_eq(ld2, ld2);
    char *test4 = "%+1235.E-2";
    res3 = sscanf(test4, "%%%lG", &ld1);
    res4 = s21_sscanf(test4, "%%%lG", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test5 = "%%+12.15";
    res3 = sscanf(test5, "%%%5lg", &ld1);
    res4 = s21_sscanf(test5, "%%%5lg", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test11 = "%-5. 1";
    res3 = sscanf(test11, "%%%lg", &ld1);
    res4 = s21_sscanf(test11, "%%%lg", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test13 = "%-0";
    res3 = sscanf(test13, "%%%4lG", &ld1);
    res4 = s21_sscanf(test13, "%%%4lG", &ld2);
    ck_assert_double_eq(ld1, ld2);
    char *test12 = "%123E-2";
    res3 = sscanf(test12, "%%%4lg", &ld1);
    res4 = s21_sscanf(test12, "%%%4lg", &ld2);
    ck_assert_double_eq(ld2, ld2);
    char *test9 = "%+999999999999999999999999Ee";
    res3 = sscanf(test9, "%%%lG", &ld1);
    res4 = s21_sscanf(test9, "%%%lG", &ld2);
    ck_assert_double_eq(ld1, ld2);
    ck_assert_int_eq(res3, res4);
    char *test10 = "+12.e-3";
    res3 = sscanf(test10, "%%%5lg", &ld1);
    res4 = s21_sscanf(test10, "%%%5lg", &ld2);
    ck_assert_double_eq(ld1, ld2);
    ck_assert_int_eq(res3, res4);
    long double hd1, hd2;
    int res5 = sscanf(test, "%%%LG", &hd1);
    int res6 = s21_sscanf(test, "%%%LG", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test6 = "%-12345e+1";
    res5 = sscanf(test6, "%%%4Lg", &hd1);
    res6 = s21_sscanf(test6, "%%%4Lg", &hd2);
    ck_assert_ldouble_eq(hd2, hd2);
    char *test7 = "%1e5";
    res5 = sscanf(test7, "%%%Lg", &hd1);
    res6 = s21_sscanf(test7, "%%%Lg", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test8 = "%1e";
    res5 = sscanf(test8, "%%%5Lg", &hd1);
    res6 = s21_sscanf(test8, "%%%5Lg", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    char *test15 = "23.23";
    res5 = sscanf(test8, "%*G");
    res6 = s21_sscanf(test15, "%*LG");
    ck_assert_ldouble_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
    char *test20 = "%+55555.555555555555555";
    res5 = sscanf(test20, "%%%LG", &hd1);
    res6 = s21_sscanf(test20, "%%%LG", &hd2);
    ck_assert_ldouble_eq(hd1, hd2);
    ck_assert_int_eq(res5, res6);
}
END_TEST


START_TEST(sscanf_test_n) {
    char *test = "123.456";
    float d1, d2;
    int n1, n2;
    int res1 = sscanf(test, "%g%n", &d1, &n1);
    int res2 = s21_sscanf(test, "%g%n", &d2, &n2);
    ck_assert_int_eq(n1, n2);
    char *test1 = "-12345.12345678";
    res1 = sscanf(test1, "%4G%n", &d1, &n1);
    res2 = s21_sscanf(test1, "%4G%n", &d2, &n2);
    ck_assert_float_eq(d2, d2);
     ck_assert_int_eq(n1, n2);
    char *test2 = "TTY";
    res1 = sscanf(test2, "%g%n", &d1, &n1);
    res2 = s21_sscanf(test2, "%g%n", &d2, &n2);
    ck_assert_double_eq(d1, d2);
     ck_assert_int_eq(n1, n2);
    char *test3 = "-12.15";
    res1 = sscanf(test3, "%5G%n", &d1, &n1);
    res2 = s21_sscanf(test3, "%5G%n", &d2, &n2);
    ck_assert_double_eq(d1, d2);
    ck_assert_int_eq(n1, n2);
    char *test4 = "string1 23 %11.23E5";
    char str1[20], str2[20];
    int dd1, dd2;
    float flo1, flo2;
    res1 = sscanf(test4, "%10s%d%n%%%2f", str1, &dd1, &n1, &flo1);
    res2 = s21_sscanf(test4, "%10s%d%n%%%2f", str2, &dd2, &n2, &flo2);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(res1, res2);
    ck_assert_float_eq(flo1, flo2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(dd1, dd2);
}
END_TEST

START_TEST(sscanf_test_star) {
    char *test4 = "string1 23 %11.23E5";
    char str1[20], str2[20];
    int dd1, dd2, n1, n2;
    float flo1, flo2;
    int res1 = sscanf(test4, "%*s%d%n%%%2f", &dd1, &n1, &flo1);
    int res2 = s21_sscanf(test4, "%*s%d%n%%%2f", &dd2, &n2, &flo2);
    ck_assert_int_eq(res1, res2);
    ck_assert_float_eq(flo1, flo2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(dd1, dd2);
    res1 = sscanf(test4, "%s%*d%n%%%2f", str1, &n1, &flo1);
    res2 = s21_sscanf(test4, "%s%*d%n%%%2f", str2, &n2, &flo2);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(res1, res2);
    ck_assert_float_eq(flo1, flo2);
    ck_assert_int_eq(n1, n2);
    res1 = sscanf(test4, "%s%*d%n%%%*f", str1, &n1);
    res2 = s21_sscanf(test4, "%s%*d%n%%%*f", str2, &n2);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_test_i) {
    char *test4 = "0x11111111111111111111111111111111111111";
    int dd1, dd2;
    int res1 = sscanf(test4, "%i", &dd1);
    int res2 = s21_sscanf(test4, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test5 = "0X123e";
    res1 = sscanf(test5, "%i", &dd1);
    res2 = s21_sscanf(test5, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test6 = "-0xFFFEEABC";
    res1 = sscanf(test6, "%i", &dd1);
    res2 = s21_sscanf(test6, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test7 = "0x123abEF";
    res1 = sscanf(test7, "%i", &dd1);
    res2 = s21_sscanf(test7, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test8 = "0777777777777777777777777777777777";
    res1 = sscanf(test8, "%i", &dd1);
    res2 = s21_sscanf(test8, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test9 = "0772130";
    res1 = sscanf(test9, "%i", &dd1);
    res2 = s21_sscanf(test9, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test10 = "-022318";
    res1 = sscanf(test10, "%i", &dd1);
    res2 = s21_sscanf(test10, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test11 = "000000000000000";
    res1 = sscanf(test11, "%i", &dd1);
    res2 = s21_sscanf(test11, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test12 = "12345678";
    res1 = sscanf(test12, "%i", &dd1);
    res2 = s21_sscanf(test12, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test13 = "123456781231213213213212313121321313231";
    res1 = sscanf(test13, "%i", &dd1);
    res2 = s21_sscanf(test13, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
    char *test14 = "-524";
    res1 = sscanf(test14, "%i", &dd1);
    res2 = s21_sscanf(test14, "%i", &dd2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(dd1, dd2);
}
END_TEST

START_TEST(sscanf_test_complex) {
    char *test1 = " abc 7723f tolua    redut 21 nsk % %19.27 0.11 1.12 +0123333665 aaaaa oxfffffabcabc";
    char *test2 = " abc 7723f tolua    redut 21 nsk % %19.27 0.11 1.12 +0123333665 aaaaa oxffffabcabc";
    char name1[20], name2[20], city1[20], city2[20], result1[200], result2[200];
    float time1 = 0, time2;
    int n1, n2;
    float f1, f2;
    long double l1, l2;
    int i1, i2, o1, o2, XX1, XX2, ix1, ix2, iX1, iX2, io1, io2;
    unsigned int x1, x2, X1, X2;
    void *p1;
    void *p2;
    char ch1, ch2;
    double E1, E2, g1, g2, G1, G2;
    unsigned int u1;
    unsigned int u2;
    unsigned int u3, u4;

    int res1 = sscanf(test1, "%x %x %s %*s %*d %s %% %n %% %20E %f %10Lf %i %p",
    &x1, &X1, name1, city1, &n1, &time1, &f1, &l1, &i1, &p1);
    int res2 = s21_sscanf(test2, "%x %x %s %*s %*d %s %% %n %% %20E %f %10Lf %i %p",
    &x2, &X2, name2, city2, &n2, &time2, &f2, &l2, &i2, &p2);
    s21_sprintf(result1, "%d %s %s %20f %d %f %LF %o %x %X %p\n",
    res1, name1, city1, time1, n1, f1, l1, i1, x1, X1, p1);
    s21_sprintf(result2, "%d %s %s %20f %d %f %LF %o %x %X %p\n",
    res2, name2, city2, time2, n2, f2, l2, i2, x2, X2, p2);
    ck_assert_str_eq(result1, result2);

    char *test3 = "q 2.1345435435 2E5 123 5 ABC1 +0xabc1 0xABC111 6777";
    char *test4 = "q 2.1345435435 2E5 123 5 ABC1 +0xabc1 0xABC111 6777";
    int res5 = sscanf(test3, "%c %*E %lg %lG %o %x %X %i %o",
    &ch1, &g1, &G1, &o1, &u1, &XX1, &ix1, &iX1);
    int res6 = s21_sscanf(test4, "%c %*E %lg %lG %o %x %X %i %o",
    &ch2, &g2, &G2, &o2, &u2, &XX2, &ix2, &iX2);

    s21_strcpy(result1, "");
    s21_strcpy(result2, "");
    s21_sprintf(result1, "%d %c %lg %lG %o %x %X %x %o\n", res5, ch1, g1, G1, o1, u1, XX1, ix1, iX1);
    s21_sprintf(result2, "%d %c %lg %lG %o %x %X %x %o\n", res6, ch2, g2, G2, o2, u2, XX2, ix2, iX2);
    ck_assert_str_eq(result1, result2);

    char* test5 = "q infinity 123.123 123 5 ABC1 0X20 123 456";
    char* test6 = "q infinity 123.123 123 5 ABC1 0X20 123 456";
    int dd1;
    int dd2;
    int res7 = sscanf(test5, "%c %lf %lE %10o %u %x %i %u %d",
    &ch1, &g1, &E1, &o1, &u1, &XX1, &ix1, &u3, &dd1);
    int res8 = s21_sscanf(test6, "%c %lf %10lE %o %u %x %i %u %d",
    &ch2, &g2, &E2, &o2, &u2, &XX2, &ix2, &u4, &dd2);
    s21_strcpy(result1, "");
    s21_strcpy(result2, "");
    s21_sprintf(result1, "%d %c %lf %lE %o %u %lx %d %u %d\n", res7, ch1, g1, E1, o1, u1, XX1, ix1, u3, dd1);
    s21_sprintf(result2, "%d %c %lf %lE %o %u %lx %d %u %d\n", res8, ch2, g2, E2, o2, u2, XX2, ix2, u4, dd2);
    ck_assert_str_eq(result1, result2);

    char* test7 = "string str";
    char* test8 = "string str";
    char str1[20] = "\0", str2[20] = "\0";
    res7 = sscanf(test5, " string %s", str1);
    res8 = s21_sscanf(test6, " string %s", str2);
    s21_strcpy(result1, "");
    s21_strcpy(result2, "");
    s21_sprintf(result1, "%d %s\n", res7, str1);
    s21_sprintf(result2, "%d %s\n", res8, str2);
    ck_assert_str_eq(result1, result2);
}
END_TEST

int convert_result(int src);
int convert_result(int src) {
    int out = 0;
    if (src < 0) {
        out = -1;
    } else if (src > 0) {
        out = 1;
    }
    return out;
}

START_TEST(s21_strlen_test) {
    ck_assert_int_eq(s21_strlen("len"), strlen("len"));
    ck_assert_int_eq(s21_strlen("\0"), strlen("\0"));
    ck_assert_int_eq(s21_strlen("this is 10"), strlen("this is 10"));
}
END_TEST

START_TEST(s21_strpbrk_test) {
    ck_assert_str_eq(s21_strpbrk("string", "no"), strpbrk("string", "no"));
    ck_assert_ptr_eq(s21_strpbrk("", ""), strpbrk("", ""));
    ck_assert_ptr_eq(s21_strpbrk("kisa", ""), strpbrk("kisa", ""));
    ck_assert_ptr_eq(s21_strpbrk("", "kisa"), strpbrk("", "kisa"));
    ck_assert_ptr_eq(s21_strpbrk("string_string", "_"), strpbrk("string_string", "_"));
    ck_assert_str_eq(s21_strpbrk("isshe", "sheis"), strpbrk("isshe", "sheis"));
    ck_assert_ptr_eq(s21_strpbrk("string", "abc"), strpbrk("string", "abc"));
    ck_assert_str_eq(s21_strpbrk("hello_world", "d"), strpbrk("hello_world", " d"));
}
END_TEST

START_TEST(s21_strrchr_test) {
    ck_assert_str_eq(s21_strrchr("abccba", 99), strrchr("abccba", 99));
    ck_assert_str_eq(s21_strrchr("aaaaaa", 97), strrchr("aaaaaa", 97));
    ck_assert_str_eq(s21_strrchr("abccba", 97), strrchr("abccba", 97));
    ck_assert_ptr_eq(s21_strrchr("", 97), strrchr("", 97));
    ck_assert_ptr_eq(s21_strrchr("abc", -10), strrchr("abc", -10));
    ck_assert_ptr_eq(s21_strrchr("abccba", 105), strrchr("abccba", 105));
    ck_assert_ptr_eq(s21_strrchr("\0", 97), strrchr("\0", 97));
}
END_TEST

START_TEST(s21_strspn_test) {
    ck_assert_int_eq(s21_strspn("this is char", "char"), strspn("this is char", "char"));
    ck_assert_int_eq(s21_strspn("thisisthis", "this"), strspn("thisisthis", "this"));
    ck_assert_int_eq(s21_strspn("", "char"), strspn("", "char"));
    ck_assert_int_eq(s21_strspn("size", "char"), strspn("size", "char"));
}
END_TEST

START_TEST(s21_strstr_test) {
    ck_assert_str_eq(s21_strstr("lenplen", "len"), strstr("lenplen", "len"));
    ck_assert_str_eq(s21_strstr("simple", "simple"), strstr("simple", "simple"));
    ck_assert_str_eq(s21_strstr("", ""), strstr("", ""));
    ck_assert_ptr_eq(s21_strstr("str", "no"), strstr("str", "no"));
    ck_assert_ptr_eq(s21_strstr("string", "string_no"), strstr("string", "string_no"));
}
END_TEST

START_TEST(s21_strtok_test) {
    char bigSentence[] = "Hello! ,World .Man";
    char bigSentence2[] = "Hello! ,World .Man";
    char tokens[] = "! , .";
    ck_assert_str_eq(s21_strtok(bigSentence, tokens), strtok(bigSentence2, tokens));
    int x = 2;
    while (x--) {
        ck_assert_str_eq(s21_strtok(NULL, tokens), strtok(NULL, tokens));
    }

    char str1[] = "Особенности национальной рыбалки - художественный, комедийный фильм.";
    char str2[] = "Особенности национальной рыбалки - художественный, комедийный фильм.";
    char *pch1 = s21_strtok(str1, " ,.-");
    char *pch2 = strtok(str2, " ,.-");
    ck_assert_str_eq(pch1, pch2);
    while (pch1 != NULL && pch2 != NULL) {
        pch1 = strtok(NULL, " ,.-");
        pch2 = s21_strtok(NULL, " ,.-");
        ck_assert_pstr_eq(pch1, pch2);
    }
}
END_TEST

START_TEST(s21_strchr_test) {
    ck_assert_str_eq(s21_strchr("string", 114), strchr("string", 114));
    ck_assert_str_eq(s21_strchr("string", 103), strchr("string", 103));
    ck_assert_ptr_eq(s21_strchr("string", 90), strchr("string", 90));
    ck_assert_str_eq(s21_strchr("string", 103), strchr("string", 103));
}
END_TEST

START_TEST(s21_strcmp_test) {
    ck_assert_int_eq(convert_result(s21_strcmp("abc", "abc")), convert_result(strcmp("abc", "abc")));
    ck_assert_int_eq(convert_result(s21_strcmp("abcd", "abc")), convert_result(strcmp("abcd", "abc")));
    ck_assert_int_eq(convert_result(s21_strcmp("abc", "abcd")), convert_result(strcmp("abc", "abcd")));
    ck_assert_int_eq(convert_result(s21_strcmp("", "")), convert_result(strcmp("", "")));
    ck_assert_int_eq(convert_result(s21_strcmp("abc", "")), convert_result(strcmp("abc", "")));
}
END_TEST

START_TEST(s21_strncmp_test) {
    ck_assert_int_eq(convert_result(s21_strncmp("abc", "abc", 3)),
                    convert_result(strncmp("abc", "abc", 3)));
    ck_assert_int_eq(convert_result(s21_strncmp("abcd", "abc", 3)),
                    convert_result(strncmp("abcd", "abc", 3)));
    ck_assert_int_eq(convert_result(s21_strncmp("abcd", "abc", 4)),
                    convert_result(strncmp("abcd", "abc", 4)));
    ck_assert_int_eq(convert_result(s21_strncmp("abc", "abcd", 4)),
                    convert_result(strncmp("abc", "abcd", 4)));
    ck_assert_int_eq(convert_result(s21_strncmp("1231", "1232", 2)),
                    convert_result(strncmp("1231", "1232", 2)));
    ck_assert_int_eq(convert_result(s21_strncmp("1231", "1232", 4)),
                    convert_result(strncmp("1231", "1232", 4)));
    ck_assert_int_eq(convert_result(s21_strncmp("1231", "1232", 10)),
                    convert_result(strncmp("1231", "1232", 10)));
    ck_assert_int_eq(convert_result(s21_strncmp("1235", "1232", 4)),
                    convert_result(strncmp("1235", "1232", 4)));
    ck_assert_int_eq(convert_result(s21_strncmp("1231", "1232", 0)),
                    convert_result(strncmp("1231", "1232", 0)));
    ck_assert_int_eq(convert_result(s21_strncmp("", "", 0)),
                    convert_result(strncmp("", "", 0)));
    ck_assert_int_eq(convert_result(s21_strncmp("", "1232", 0)),
                    convert_result(strncmp("", "1232", 0)));
    ck_assert_int_eq(convert_result(s21_strncmp("", "1232", 3)),
                    convert_result(strncmp("", "1232", 3)));
    ck_assert_int_eq(convert_result(s21_strncmp("1231", "1232", -4)),
                    convert_result(strncmp("1231", "1232", -4)));
    ck_assert_int_eq(convert_result(s21_strncmp("", "1232", 100)),
                    convert_result(strncmp("", "1232", 100)));
    ck_assert_int_eq(convert_result(s21_strncmp("1231", "", 3)),
                    convert_result(strncmp("1231", "", 3)));
}
END_TEST

START_TEST(s21_strcspn_test) {
    ck_assert_int_eq(s21_strcspn("*****code", "abc"), strcspn("*****code", "abc"));
    ck_assert_int_eq(s21_strcspn("code", "abc"), strcspn("code", "abc"));
    ck_assert_int_eq(s21_strcspn("", "abc"), strcspn("", "abc"));
    ck_assert_int_eq(s21_strcspn("", ""), strcspn("", ""));
    ck_assert_int_eq(s21_strcspn("str", "a"), strcspn("str", "a"));
}
END_TEST

START_TEST(s21_strcpy_test) {
    char dest[50] = "";
    char destination[50] = "";
    char src[] = "hey)) have a good day!";
    ck_assert_str_eq(s21_strcpy(dest, src), strcpy(destination, src));
    char src1[] = "";
    ck_assert_str_eq(s21_strcpy(dest, src1), strcpy(destination, src1));
}
END_TEST

START_TEST(s21_strncpy_test) {
    char dest[20] = "";
    char destination[20] = "";
    char src[] = "string";
    ck_assert_str_eq(s21_strncpy(dest, src, 4), strncpy(destination, src, 4));
    ck_assert_str_eq(s21_strncpy(dest, src, 7), strncpy(destination, src, 7));
    char src1[] = "";
    ck_assert_str_eq(s21_strncpy(dest, src1, 3), strncpy(destination, src1, 3));
}
END_TEST

START_TEST(s21_to_upper_test) {
    char *temp = s21_to_upper("string_to_UPPER");
    ck_assert_str_eq(temp, "STRING_TO_UPPER");
    free(temp);
    temp = s21_to_upper("0123abc456def789");
    ck_assert_str_eq(temp, "0123ABC456DEF789");
    free(temp);
    temp = s21_to_upper("");
    ck_assert_str_eq(temp, "");
    free(temp);
}
END_TEST

START_TEST(s21_to_lower_test) {
    char *temp = s21_to_lower("STRING_to_LOWER");
    ck_assert_str_eq(temp, "string_to_lower");
    free(temp);
    temp = s21_to_lower("0123ABC456DEF789");
    ck_assert_str_eq(temp, "0123abc456def789");
    free(temp);
    temp = s21_to_lower("");
    ck_assert_str_eq(temp, "");
    free(temp);
}
END_TEST

START_TEST(s21_insert_test) {
    char *temp = s21_insert("poka", "privet", 1);
    ck_assert_str_eq(temp, "pprivetoka");
    free(temp);
    temp = s21_insert("string", "III", 3);
    ck_assert_str_eq(temp, "strIIIing");
    free(temp);
    temp = s21_insert("", "hey", 0);
    ck_assert_str_eq(temp, "hey");
    free(temp);
    temp = s21_insert("hey", "", 2);
    ck_assert_str_eq(temp, "hey");
    free(temp);
    temp = s21_insert("", "", 3);
    ck_assert_ptr_eq(temp, NULL);
    free(temp);
    temp = s21_insert("", "", 0);
    ck_assert_str_eq(temp, "");
    free(temp);
    char *test1 = s21_insert("string", "str", 10);
    ck_assert_ptr_eq(test1, NULL);
    char *test2 = s21_insert("string", "str", 0);
    ck_assert_str_eq(test2, "strstring");
    char *test3 = s21_insert(NULL, "str", 0);
    ck_assert_ptr_eq(test3, NULL);
    char *test4 = s21_insert("string", NULL, 0);
    ck_assert_ptr_eq(test4, NULL);
    char *test5 = s21_insert("string", "str", -1);
    ck_assert_ptr_eq(test5, NULL);
    char *test6 = s21_insert("stringasdasdasdstr", "str", 2);
    ck_assert_str_eq(test6, "ststrringasdasdasdstr");
    free(test2);
    free(test6);
    temp = s21_insert("string", "III", 3);
    ck_assert_str_eq(temp, "strIIIing");
    free(temp);
    temp = s21_insert("", "hey", 0);
    ck_assert_str_eq(temp, "hey");
    free(temp);
    temp = s21_insert("hey", "", 2);
    ck_assert_str_eq(temp, "hey");
    free(temp);
    temp = s21_insert("", "", 3);
    ck_assert_ptr_eq(temp, NULL);
    free(temp);
    temp = s21_insert("", "", 0);
    ck_assert_pstr_eq(temp, "");
    free(temp);
    temp = s21_insert("string", "III", 0);
    ck_assert_str_eq(temp, "IIIstring");
    free(temp);
    temp = s21_insert("string", "III", -5);
    ck_assert_ptr_eq(temp, NULL);
    free(temp);
    temp = s21_insert("hey", "", 0);
    ck_assert_str_eq(temp, "hey");
    free(temp);
    temp = s21_insert("", "", 0);
    ck_assert_str_eq(temp, "");
    free(temp);
}
END_TEST

START_TEST(s21_trim_test) {
    char *temp = s21_trim("___u___", "*_123456789");
    ck_assert_str_eq(temp, "u");
    free(temp);
    temp = s21_trim("___u___", "_");
    ck_assert_str_eq(temp, "u");
    free(temp);
    temp = s21_trim("___u___", "u_");
    ck_assert_str_eq(temp, "");
    free(temp);
    temp = s21_trim("___u___", "___u___");
    ck_assert_str_eq(temp, "");
    free(temp);
    temp = s21_trim("___u___", "u");
    ck_assert_str_eq(temp, "___u___");
    free(temp);
    temp = s21_trim("123abc456def789", "123456789");
    ck_assert_str_eq(temp, "abc456def");
    free(temp);
    temp = s21_trim("***___123abc456def789___***", "*_123456789abcdef");
    ck_assert_str_eq(temp, "");
    free(temp);
    temp = s21_trim("***___123abc456def789___***", "p");
    ck_assert_str_eq(temp, "***___123abc456def789___***");
    free(temp);
    temp = s21_trim("", "123");
    ck_assert_str_eq(temp, "");
    free(temp);
    temp = s21_trim(NULL, "u_");
    ck_assert_ptr_eq(temp, NULL);
    free(temp);
    temp = s21_trim("___u___", NULL);
    ck_assert_ptr_eq(temp, NULL);
    free(temp);
    temp = s21_trim("", "");
    ck_assert_str_eq(temp, "");
    free(temp);
}
END_TEST

START_TEST(s21_memchr_test) {
    ck_assert_str_eq(s21_memchr("Hello world\0", 'o', 12), memchr("Hello world\0", 'o', 12));
    ck_assert_str_eq(s21_memchr("Hello world\n\0", 'o', 13), memchr("Hello world\n\0", 'o', 13));
    ck_assert_str_eq(s21_memchr("a\n\0", 'a', 3), memchr("a\n\0", 'a', 3));
    ck_assert_str_eq(s21_memchr(" \n\0", ' ', 3), memchr(" \n\0", ' ', 3));
    ck_assert_str_eq(s21_memchr(" \0", ' ', 2), memchr(" \0", ' ', 2));
    ck_assert_str_eq(s21_memchr("\n\0", '\0', 2), memchr("\n\0", '\0', 2));
    ck_assert_str_eq(s21_memchr("\0", '\0', 1), memchr("\0", '\0', 1));
}
END_TEST

START_TEST(s21_memcmp_test) {
    ck_assert_int_eq(convert_result(s21_memcmp("Hello world\0", "Hello world\0", 12)),
                        convert_result(memcmp("Hello world\0", "Hello world\0", 12)));
    ck_assert_int_eq(convert_result(s21_memcmp("Hello world\0", "Hello world\n\0", 13)),
                        convert_result(memcmp("Hello world\0", "Hello world\n\0", 13)));
    ck_assert_int_eq(convert_result(s21_memcmp("Hello world\n\0", "a\n\0", 12)),
                     convert_result(memcmp("Hello world\n\0", "a\n\0", 12)));
    ck_assert_int_eq(convert_result(s21_memcmp("a\n\0", " \n\0", 3)),
                     convert_result(memcmp("a\n\0", " \n\0", 3)));
    ck_assert_int_eq(convert_result(s21_memcmp(" \n\0", " \0", 2)),
                     convert_result(memcmp(" \n\0", " \0", 2)));
    ck_assert_int_eq(convert_result(s21_memcmp(" \0", "\n\0", 2)),
                     convert_result(memcmp(" \0", "\n\0", 2)));
    ck_assert_int_eq(convert_result(s21_memcmp("\n\0", "\0", 2)),
                     convert_result(memcmp("\n\0", "\0", 2)));
}
END_TEST

START_TEST(s21_memcpy_test) {
    char str_mem0[13] = "Hello\0";
    ck_assert_str_eq(s21_memcpy(str_mem0, "Hello world\0", 12), memcpy(str_mem0, "Hello world\0", 12));
    ck_assert_str_eq(s21_memcpy(str_mem0, "Hello world\n\0", 13), memcpy(str_mem0, "Hello world\n\0", 13));
    ck_assert_str_eq(s21_memcpy(str_mem0, "a\n\0", 3), memcpy(str_mem0, "a\n\0", 3));
    ck_assert_str_eq(s21_memcpy(str_mem0, " \n\0", 3), memcpy(str_mem0, " \n\0", 3));
    ck_assert_str_eq(s21_memcpy(str_mem0, " \0", 2), memcpy(str_mem0, " \0", 2));
    ck_assert_str_eq(s21_memcpy(str_mem0, "\n\0", 2), memcpy(str_mem0, "\n\0", 2));
    ck_assert_str_eq(s21_memcpy(str_mem0, "\0", 1), memcpy(str_mem0, "\0", 1));
}
END_TEST

START_TEST(s21_memmove_test) {
    char str_mem0[13] = "Hello\0";
    ck_assert_str_eq(s21_memmove(str_mem0, "Hello world\0", 12), memmove(str_mem0, "Hello world\0", 12));
    ck_assert_str_eq(s21_memmove(str_mem0, "Hello world\n\0", 13), memmove(str_mem0, "Hello world\n\0", 13));
    ck_assert_str_eq(s21_memmove(str_mem0 + 6, "a\n\0", 3), memmove(str_mem0 + 6, "a\n\0", 3));
    ck_assert_str_eq(s21_memmove(str_mem0 + 7, " \n\0", 3), memmove(str_mem0 + 7, " \n\0", 3));
    ck_assert_str_eq(s21_memmove(str_mem0 + 8, " \0", 2), memmove(str_mem0 + 8, " \0", 2));
    ck_assert_str_eq(s21_memmove(str_mem0 + 9, "\n\0", 2), memmove(str_mem0 + 9, "\n\0", 2));
    ck_assert_str_eq(s21_memmove(str_mem0 + 10, "\0", 1), memmove(str_mem0 + 10, "\0", 1));
}
END_TEST

START_TEST(s21_memset_test) {
    char str_mem0[13] = "Hello\0";
    ck_assert_str_eq(s21_memset(str_mem0 + 6, 'w', 5), memset(str_mem0 + 6, 'w', 5));
    ck_assert_str_eq(s21_memset(str_mem0 + 6, 'a', 4), memset(str_mem0 + 6, 'a', 4));
    ck_assert_str_eq(s21_memset(str_mem0 + 6, '\0', 3), memset(str_mem0 + 6, '\0', 3));
    ck_assert_str_eq(s21_memset(str_mem0 + 6, '\n', 2), memset(str_mem0 + 6, '\n', 2));
    ck_assert_str_eq(s21_memset(str_mem0 + 5, '*', 1), memset(str_mem0 + 5, '*', 1));
    ck_assert_str_eq(s21_memset(str_mem0 + 4, ' ', 2), memset(str_mem0 + 4, ' ', 2));
    ck_assert_str_eq(s21_memset(str_mem0 + 3, '.', 2), memset(str_mem0 + 3, '.', 2));
}
END_TEST

START_TEST(s21_strcat_test) {
    char str_cat0[100] = "";
    char str_cat1[100] = "";
    ck_assert_str_eq(s21_strcat(str_cat0, "Hello world\0"), strcat(str_cat1, "Hello world\0"));
    ck_assert_str_eq(s21_strcat(str_cat0, "Hello world\n\0"), strcat(str_cat1, "Hello world\n\0"));
    ck_assert_str_eq(s21_strcat(str_cat0, "a\n\0"), strcat(str_cat1, "a\n\0"));
    ck_assert_str_eq(s21_strcat(str_cat0, " \n\0"), strcat(str_cat1, " \n\0"));
    ck_assert_str_eq(s21_strcat(str_cat0, " \0"), strcat(str_cat1, " \0"));
    ck_assert_str_eq(s21_strcat(str_cat0, "\n\0"), strcat(str_cat1, "\n\0"));
    ck_assert_str_eq(s21_strcat(str_cat0, "\0"), strcat(str_cat1, "\0"));
}
END_TEST

START_TEST(s21_strncat_test) {
    char str_ncat0[100] = "";
    char str_ncat1[100] = "";
    ck_assert_str_eq(s21_strncat(str_ncat0, "Hello world\0", 13),
                        strncat(str_ncat1, "Hello world\0", 13));
    ck_assert_str_eq(s21_strncat(str_ncat0, "Hello world\n\0", 14),
                        strncat(str_ncat1, "Hello world\n\0", 14));
    ck_assert_str_eq(s21_strncat(str_ncat0, "a\n\0", 4),
                strncat(str_ncat1, "a\n\0", 4));
    ck_assert_str_eq(s21_strncat(str_ncat0, " \n\0", 4), strncat(str_ncat1, " \n\0", 4));
    ck_assert_str_eq(s21_strncat(str_ncat0, " \0", 3), strncat(str_ncat1, " \0", 3));
    ck_assert_str_eq(s21_strncat(str_ncat0, "\n\0", 3), strncat(str_ncat1, "\n\0", 3));
    ck_assert_str_eq(s21_strncat(str_ncat0, "\0", 2), strncat(str_ncat1, "\0", 2));
}
END_TEST

START_TEST(s21_sprintf_test) {
    char str0[200], str1[200];
    int res0, res1, n0, n1;
    short int n2, n3;
    long int n4, n5;
    void *pt;

// c
    res0 = sprintf(str0, "%c|%5c|%-5c||%-*c", 'c', 'c', 'c', 5, 'c');
    res1 = s21_sprintf(str1, "%c|%5c|%-5c||%-*c", 'c', 'c', 'c', 5, 'c');
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

// d
    res0 = sprintf(str0, "%d|%.6ld|%hd|%6.*d|%6ld|%6.6hd", 1, (long)-10, 10, 6, 10, (long)-10, 10);
    res1 = s21_sprintf(str1, "%d|%.6ld|%hd|%6.*d|%6ld|%6.6hd", 1, (long)-10, 10, 6, 10, (long)-10, 10);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%*d|%-6d|%+d|% 6d|%-+8.6d|%06d||%-+*.*ld",
        6, 10, -10, 10, 10, -10, -10, 10, 8, (long)-10);
    res1 = s21_sprintf(str1, "%*d|%-6d|%+d|% 6d|%-+8.6d|%06d||%-+*.*ld",
        6, 10, -10, 10, 10, -10, -10, 10, 8, (long)-10);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

// i
    res0 = sprintf(str0, "%i|%.7li|%hi|%7.*i|%7li|%7.7hi", 102, (long)-102, 102, 7, 102, (long)-102, 102);
    res1 = s21_sprintf(str1, "%i|%.7li|%hi|%7.*i|%7li|%7.7hi", 102, (long)-102, 102, 7, 102, (long)-102, 102);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%*i|%-7i|%+i|% 7i|%-+9.7i|%07i||%-+*.*li",
        7, 102, -102, 102, 102, -102, -102, 102, 7, (long)-102);
    res1 = s21_sprintf(str1, "%*i|%-7i|%+i|% 7i|%-+9.7i|%07i||%-+*.*li",
        7, 102, -102, 102, 102, -102, -102, 102, 7, (long)-102);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

// e E
    res0 = sprintf(str0, "%e|%.7Le|%7.*e|%7Le|%7.7e", 5.2e+5,
        (long double)-5.2e-5, 7, 5.2e-0, (long double)-0.10e-1, 10.2);
    res1 = s21_sprintf(str1, "%e|%.7Le|%7.*e|%7Le|%7.7e", 5.2e+5,
        (long double)-5.2e-5, 7, 5.2e-0, (long double)-0.10e-1, 10.2);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    long double test = 1E-10;

    res0 = sprintf(str0, "%e|%e|%.7Le|%7.*e|%7Le|%7.7e", 5.2231213e-1,
        0.0, test, 7, 5.2e-1, (long double)-0.11e10, 11110.2e1);
    res1 = s21_sprintf(str1, "%e|%e|%.7Le|%7.*e|%7Le|%7.7e",  5.2231213e-1,
        0.0, test, 7, 5.2e-1, (long double)-0.11e10, 11110.2e1);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%e|%.7Le|%7.*e|%.2Le|%7.7e", 5.2200000e-2,
        test, 7, 5.e-1, (long double)-0.10e-1, 11110.2e1);
    res1 = s21_sprintf(str1, "%e|%.7Le|%7.*e|%.2Le|%7.7e", 5.2200000e-2,
        test, 7, 5.e-1, (long double)-0.10e-1, 11110.2e1);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%.7Le|%1.*e|%7.7e", test,
        7, 5.123e10, -11.2e10);
    res1 = s21_sprintf(str1, "%.7Le|%1.*e|%7.7e", test,
        7, 5.123e10, -11.2e10);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%#*E|%-7E|%+E|% 7E|%-+9.7E|%07E||%-+#*.*LE", 3, 0.02e-0, -10.2, 0.11e-10,
        -0.11e-10, -0.10e-10, 0.9e+9, 1, 7, (long double)-10.2);
    res1 = s21_sprintf(str1, "%#*E|%-7E|%+E|% 7E|%-+9.7E|%07E||%-+#*.*LE", 3, 0.02e-0, -10.2, 0.11e-10,
        -0.11e-10, -0.10e-10, 0.9e+9, 1, 7, (long double)-10.2);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

// f
    res0 = sprintf(str0, "%f|%.7Lf|%7.*f|%7Lf|%7.7f",
        10.2, (long double)-10.2, 7, 10.2, (long double)-10.2, 10.2);
    res1 = s21_sprintf(str1, "%f|%.7Lf|%7.*f|%7Lf|%7.7f",
        10.2, (long double)-10.2, 7, 10.2, (long double)-10.2, 10.2);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%#*f|%-7f|%+f|% 7f|%-+9.7f|%07f||%-+#*.*Lf",
        3, 10.2, -10.2, 10.2, 10.2, -10.2, -10.2, 1, 7, (long double)-10.2);
    res1 = s21_sprintf(str1, "%#*f|%-7f|%+f|% 7f|%-+9.7f|%07f||%-+#*.*Lf",
        3, 10.2, -10.2, 10.2, 10.2, -10.2, -10.2, 1, 7, (long double)-10.2);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

// g G
    res0 = sprintf(str0, "%g|%.7Lg|%7.*g|%7Lg|%7.7g",
        10.23, (long double)-10.2, 7, 10.2, (long double)-10.2, 10.2);
    res1 = s21_sprintf(str1, "%g|%.7Lg|%7.*g|%7Lg|%7.7g",
        10.23, (long double)-10.2, 7, 10.2, (long double)-10.2, 10.2);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%#*G|%-7G|%+G|% 7G|%-+9.7G|%07G||%-+#*.*LG",
        1, 5.2e-5, -10.2, 10.2, 10.2, -10.2, -10.2, 1, 7, (long double)-10.2);
    res1 = s21_sprintf(str1, "%#*G|%-7G|%+G|% 7G|%-+9.7G|%07G||%-+#*.*LG",
        1, 5.2e-5, -10.2, 10.2, 10.2, -10.2, -10.2, 1, 7, (long double)-10.2);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

// o without ub
    res0 = sprintf(str0, "%o|%.6lo|%ho|%6.*o|%6lo|%6.6ho", 10, (long)10, 10, 6, 10, (long)10, 10);
    res1 = s21_sprintf(str1, "%o|%.6lo|%ho|%6.*o|%6lo|%6.6ho", 10, (long)10, 10, 6, 10, (long)10, 10);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%*o|%-6o|%6o|%-8.6o|%06o||%-*.*lo", 6, 10, 10, 10, 10, 10, 10, 8, (long)10);
    res1 = s21_sprintf(str1, "%*o|%-6o|%6o|%-8.6o|%06o||%-*.*lo", 6, 10, 10, 10, 10, 10, 10, 8, (long)10);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

// s
    res0 = sprintf(str0, "%s|%.5s|%s|%6.*s|%6s|%6.6s",
        "Hello", "Hello", "Hello", 6, "Hello", "Hello", "Hello");
    res1 = s21_sprintf(str1, "%s|%.5s|%s|%6.*s|%6s|%6.6s",
        "Hello", "Hello", "Hello", 6, "Hello", "Hello", "Hello");
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%*s|%-6s|%6s|%-8.6s|%1s||%-*.*s", 6,
        "Hello", "Hello", "Hello", "Hello", "Hello", 10, 8, "Hello");
    res1 = s21_sprintf(str1, "%*s|%-6s|%6s|%-8.6s|%1s||%-*.*s", 6,
        "Hello", "Hello", "Hello", "Hello", "Hello", 10, 8, "Hello");
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

// u without ub
    res0 = sprintf(str0, "%u|%.6lu|%hu|%6.*u|%6lu|%6.6hu", 10, (long)10, 10, 6, 10, (long)10, 10);
    res1 = s21_sprintf(str1, "%u|%.6lu|%hu|%6.*u|%6lu|%6.6hu", 10, (long)10, 10, 6, 10, (long)10, 10);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%*u|%-6u|%6u|%-8.6u|%06u||%-*.*lu", 6, 10, 10, 10, 10, 10, 10, 8, (long)10);
    res1 = s21_sprintf(str1, "%*u|%-6u|%6u|%-8.6u|%06u||%-*.*lu", 6, 10, 10, 10, 10, 10, 10, 8, (long)10);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

// x X n without ub
    res0 = sprintf(str0, "%n%x|%#x|%.6lx|%hx|%6.*x|%6lx|%6.6hx",
        &n0, 10, 10, (long)10, 10, 6, 10, (long)10, 10);
    res1 = s21_sprintf(str1, "%n%x|%#x|%.6lx|%hx|%6.*x|%6lx|%6.6hx",
        &n1, 10, 10, (long)10, 10, 6, 10, (long)10, 10);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
    ck_assert_int_eq(n0, n1);

    res0 = sprintf(str0, "%*X|%-6X|%6X|%-8.6X%hn|%06X||%-#*.*lX",
        6, 10, 10, 10, 10, &n2, 10, 10, 8, (long)10);
    res1 = s21_sprintf(str1, "%*X|%-6X|%6X|%-8.6X%hn|%06X||%-#*.*lX",
        6, 10, 10, 10, 10, &n3, 10, 10, 8, (long)10);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
    ck_assert_int_eq(n2, n3);

// p n %
    res0 = sprintf(str0, "%%%p|%6p|%*p|%%%-20p%%|%20p||%ln%-*p%%", pt, pt, 6, pt, pt, pt, &n4, 10, pt);
    res1 = s21_sprintf(str1, "%%%p|%6p|%*p|%%%-20p%%|%20p||%ln%-*p%%", pt, pt, 6, pt, pt, pt, &n5, 10, pt);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
    ck_assert_int_eq(n4, n5);

    res0 = sprintf(str0, "Hel%c%-2c%.9s", 'l', 'o', "world");
    res1 = s21_sprintf(str1, "Hel%c%-2c%.9s", 'l', 'o', "world");
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);

    res0 = sprintf(str0, "%p - ptr, %+3.6d - d%nec, %#5x - hex", pt, -125, &n0, 125);
    res1 = s21_sprintf(str1, "%p - ptr, %+3.6d - d%nec, %#5x - hex", pt, -125, &n1, 125);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
    ck_assert_int_eq(n0, n1);

    res0 = sprintf(str0, "%o%ln - o, %+6.3lf - f, %e - e\n", 80, &n4, -12.5, 12.5);
    res1 = s21_sprintf(str1, "%o%ln - o, %+6.3lf - f, %e - e\n", 80, &n5, -12.5, 12.5);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
    ck_assert_int_eq(n4, n5);

    res0 = sprintf(str0, "G %5G, %hng %.1g", 8.1e2, &n2, 1.1e2);
    res1 = s21_sprintf(str1, "G %5G, %hng %.1g", 8.1e2, &n3, 1.1e2);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
    ck_assert_int_eq(n2, n3);

    res0 = sprintf(str0, "%nUpper %*X, lower %4hx", &n0, 8, 123, 123456);
    res1 = s21_sprintf(str1, "%nUpper %*X, lower %4hx", &n1, 8, 123, 123456);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
    ck_assert_int_eq(n0, n1);

    res0 = sprintf(str0, "%.6hd - sint, %+3.*ld - lint%n, %#10lx - hex",
    24, 6, (long)-125, &n0, (long)1253456789);
    res1 = s21_sprintf(str1, "%.6hd - sint, %+3.*ld - lint%n, %#10lx - hex",
    24, 6, (long)-125, &n1, (long)1253456789);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
    ck_assert_int_eq(n0, n1);

    res0 = sprintf(str0, "%010hd % 15.*Lf %n %#10x %4f", 24, 6, (long double)1.23, &n0, 300, 0.0);
    res1 = s21_sprintf(str1, "%010hd % 15.*Lf %n %#10x %4f", 24, 6, (long double)1.23, &n1, 300, 0.0);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
    ck_assert_int_eq(n0, n1);

    res0 = sprintf(str0, "%2i%2.1f%.3u%%%.0f", 345, 6.789, 2, (float)0);
    res1 = s21_sprintf(str1, "%2i%2.1f%.3u%%%.0f", 345, 6.789, 2, (float)0);
    ck_assert_str_eq(str0, str1);
    ck_assert_int_eq(res0, res1);
}
END_TEST

START_TEST(s21_scanf_test) {
    char *test1 = " abc 7723f tolua    redut 21 nsk % %19.27 0.11 1.12 +0123333665 aaaaa oxfffffabcabc";
    char *test2 = " abc 7723f tolua    redut 21 nsk % %19.27 0.11 1.12 +0123333665 aaaaa oxffffabcabc";
    char name1[20], name2[20], city1[20], city2[20], result1[200], result2[200];
    float time1 = 0, time2;
    int n1, n2;
    float f1, f2;
    long double l1, l2;
    int i1, i2, o1, o2, XX1, XX2, ix1, ix2, iX1, iX2, io1, io2;
    unsigned int x1, x2, X1, X2;
    void *p1;
    void *p2;
    char ch1, ch2;
    double E1, E2, g1, g2, G1, G2;
    unsigned int u1;
    unsigned int u2;
    unsigned int u3, u4;

    int res1 = sscanf(test1, "%x %x %s %*s %*d %s %% %n %% %20E %f %10Lf %i %p",
    &x1, &X1, name1, city1, &n1, &time1, &f1, &l1, &i1, &p1);
    int res2 = s21_sscanf(test2, "%x %x %s %*s %*d %s %% %n %% %20E %f %10Lf %i %p",
    &x2, &X2, name2, city2, &n2, &time2, &f2, &l2, &i2, &p2);
    s21_sprintf(result1, "%d %s %s %20f %d %f %LF %o %x %X %p\n",
    res1, name1, city1, time1, n1, f1, l1, i1, x1, X1, p1);
    s21_sprintf(result2, "%d %s %s %20f %d %f %LF %o %x %X %p\n",
    res2, name2, city2, time2, n2, f2, l2, i2, x2, X2, p2);
    ck_assert_str_eq(result1, result2);

    char *test3 = "q 2.1345435435 2E5 123 5 ABC1 +0xabc1 0xABC111 6777";
    char *test4 = "q 2.1345435435 2E5 123 5 ABC1 +0xabc1 0xABC111 6777";
    int res5 = sscanf(test3, "%c %lE %lg %lG %o %x %X %i %o",
    &ch1, &E1, &g1, &G1, &o1, &u1, &XX1, &ix1, &iX1);
    int res6 = s21_sscanf(test4, "%c %lE %lg %lG %o %x %X %i %o",
    &ch2, &E2, &g2, &G2, &o2, &u2, &XX2, &ix2, &iX2);

    s21_strcpy(result1, "");
    s21_strcpy(result2, "");
    s21_sprintf(result1, "%d %c %lE %lg %lG %o %x %X %x %o\n", res5, ch1, E1, g1, G1, o1, u1, XX1, ix1, iX1);
    s21_sprintf(result2, "%d %c %lE %lg %lG %o %x %X %x %o\n", res6, ch2, E2, g2, G2, o2, u2, XX2, ix2, iX2);
    ck_assert_str_eq(result1, result2);

    char* test5 = "q infinity 123.123 123 5 ABC1 0X20 123 456";
    char* test6 = "q infinity 123.123 123 5 ABC1 0X20 123 456";
    int dd1;
    int dd2;
    int res7 = sscanf(test5, "%c %lf %lE %10o %u %x %i %u %d",
    &ch1, &g1, &E1, &o1, &u1, &XX1, &ix1, &u3, &dd1);
    int res8 = s21_sscanf(test6, "%c %lf %10lE %o %u %x %i %u %d",
    &ch2, &g2, &E2, &o2, &u2, &XX2, &ix2, &u4, &dd2);
    s21_strcpy(result1, "");
    s21_strcpy(result2, "");
    s21_sprintf(result1, "%d %c %lf %lE %o %u %lx %d %u %d\n", res7, ch1, g1, E1, o1, u1, XX1, ix1, u3, dd1);
    s21_sprintf(result2, "%d %c %lf %lE %o %u %lx %d %u %d\n", res8, ch2, g2, E2, o2, u2, XX2, ix2, u4, dd2);
    ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_error_test) {
    for (int i = 0; i < 140; i++)
        ck_assert_str_eq(s21_strerror(i), strerror(i));
}
END_TEST



int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, sscanf_test_char);
    tcase_add_test(tc1_1, sscanf_test_string);
    tcase_add_test(tc1_1, sscanf_test_int);
    tcase_add_test(tc1_1, sscanf_test_uint);
    tcase_add_test(tc1_1, sscanf_test_oint);
    tcase_add_test(tc1_1, sscanf_test_xint);
    tcase_add_test(tc1_1, sscanf_test_Xint);
    tcase_add_test(tc1_1, sscanf_test_pointer);
    tcase_add_test(tc1_1, sscanf_test_floatf);
    tcase_add_test(tc1_1, sscanf_test_floate);
    tcase_add_test(tc1_1, sscanf_test_floatg);
    tcase_add_test(tc1_1, sscanf_test_proc);
    tcase_add_test(tc1_1, sscanf_test_n);
    tcase_add_test(tc1_1, sscanf_test_complex);
    tcase_add_test(tc1_1, sscanf_test_star);
    tcase_add_test(tc1_1, sscanf_test_i);
    tcase_add_test(tc1_1, s21_strlen_test);
    tcase_add_test(tc1_1, s21_strpbrk_test);
    tcase_add_test(tc1_1, s21_strrchr_test);
    tcase_add_test(tc1_1, s21_strspn_test);
    tcase_add_test(tc1_1, s21_strstr_test);
    tcase_add_test(tc1_1, s21_strtok_test);
    tcase_add_test(tc1_1, s21_strchr_test);
    tcase_add_test(tc1_1, s21_strcmp_test);
    tcase_add_test(tc1_1, s21_strncmp_test);
    tcase_add_test(tc1_1, s21_strcspn_test);
    tcase_add_test(tc1_1, s21_strcpy_test);
    tcase_add_test(tc1_1, s21_strncpy_test);
    tcase_add_test(tc1_1, s21_to_upper_test);
    tcase_add_test(tc1_1, s21_to_lower_test);
    tcase_add_test(tc1_1, s21_memchr_test);
    tcase_add_test(tc1_1, s21_memcmp_test);
    tcase_add_test(tc1_1, s21_memcpy_test);
    tcase_add_test(tc1_1, s21_memmove_test);
    tcase_add_test(tc1_1, s21_memset_test);
    tcase_add_test(tc1_1, s21_strcat_test);
    tcase_add_test(tc1_1, s21_strncat_test);
    tcase_add_test(tc1_1, s21_error_test);
    tcase_add_test(tc1_1, s21_sprintf_test);
    tcase_add_test(tc1_1, s21_trim_test);
    tcase_add_test(tc1_1, s21_insert_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
