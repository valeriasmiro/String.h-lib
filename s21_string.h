#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>

#define MAX 1000
#define EPSILON (long double)1e-15
#define s21_NULL ((void*)0)
typedef unsigned long s21_size_t;

size_t s21_strlen(const char* str);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strrchr(const char* str, int c);
size_t s21_strspn(const char* str1, const char* str2);
char* s21_strstr(const char* haystack, const char* needle);
char* s21_strtok(char* str, const char* delim);
int is_char_in_string(char current, const char* delim);
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memmove(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char* str1, const char* str2);
int s21_strncmp(const char* str1, const char* str2, size_t n);
size_t s21_strcspn(const char* str1, const char* str2);
char* s21_strcpy(char* dest, const char* src);
char* s21_strncpy(char* dest, const char* src, size_t n);
void* s21_to_upper(const char* str);
void* s21_to_lower(const char* str);
void* s21_insert(const char* src, const char* str, size_t start_index);
void* s21_trim(const char* src, const char* trim_chars);
char* s21_strerror(int num);

int s21_sscanf(const char* str, const char* format, ...);
int skip_delimeters(const char** str);
void width_handler(const char** str, int* width, int* no_assign);
int is_width(char c);
void lenght_handler(const char** str, char* lflag);
char is_lenght(char c);

int get_spec(const char** format, const char* str, int* base);
int base_int_handler(const char** format, const char* str, int* base);
int get_base_i(const char* str, int* base);
int other_handler(const char** format, int* base);
int char_handler(const char** format);
int float_handler(const char** format);

char* get_string(char res[], const char* str, int spec, int* width);
void get_exact_width_int(const char* str, int* counter, int right, int left, int width);
void get_exact_width_hex(const char* str, int* counter, int width);
void get_string_int(char res[], const char* str, int spec, int* width);
void get_string_str(char res[], const char* str, int* width);
size_t read_float(int width, const char* str);
void get_string_float(const char res[], int* width, const char* str);

void write_to_var(int spec, int base, va_list* list, char* string, char lflag, int count, int width);
void write_float(va_list* list, char* string, char lflag);
void write_int(int spec, int base, va_list* list, char* string, char lflag);
void write_str(int spec, const char* string, va_list* list, int width);
void write_pointer(int base, va_list* list, char* string);

int s21_sprintf(char *str, const char *format, ...);
void try_set_flag(char **flags, char **ch);
int try_set_width(char **ch, va_list args);
int try_set_prec(char **ch, va_list args);
char try_set_length(char **ch);
int set_spec(char *ch, char length);
int set_base(char *ch);
int set_case(char *ch);
void to_string(char **str, char ch, int spec, va_list args, int base, int *prec, const char *prsd);
void int_to_string(char **str, int num, char ch, va_list args, int base, int prec, const char *prsd);
void sint_to_string(char **str, int num, char ch, va_list args, int base, int prec, const char *prsd);
void lint_to_string(char **str, int num, char ch, va_list args, int base, int prec, const char *prsd);
void check_base(char **str, long int base, int num, int prec);
void dec_to_hex(char **str, int num);
void str_reverse(char **str);
int dec_to_oct(int num);
void i_to_a(char **str, long int num);
int digits_count(long int num);
void d_to_string(char **str, int num, char ch, va_list args, int *prec);
void d_conv(char **str, double num, char ch, int *prec);
void f_style_conversion(char **str, long double num, int prec);
void f_to_a(char **str, long double num, int prec, int *pt, int *sg);
void cut_zeroes(char **str);
void add_zeroes(char **str, char prec, int exp, int are_pre);
void d_to_sci_not(char **str, long double num, int prec);
void ch_to_string(char **str, int num, va_list args, int prec);
void vp_to_string(char **str, va_list args);
void address_to_str(char **str, uintmax_t num, int base);
void add_prefix(char **str, char pref);
void add_flag(char **str, char ch, char *flags, int width, int prec);
void add_width(char **str, char ch, char flag, int width);
int dig_before_point(const char *str);
void set_up_case(char **str, int to_upper);


#endif  // SRC_S21_STRING_H_
