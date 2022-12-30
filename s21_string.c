#include "s21_string.h"
#include "s21_strerror.h"

size_t s21_strlen(const char* str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* s21_strpbrk(const char* str1, const char* str2) {
    char* res = NULL;
    int i = 0;
    int len_1 = s21_strlen(str1);
    int len_2 = s21_strlen(str2);
    if ((len_1 > 0 && len_2 > 0)) {
        while (is_char_in_string(*(str1 + i), str2) == 0 && i < len_1) {
            i++;
        }
        if (i != len_1)
            res = (char*)str1 + i;
    }
    return (char*)res;
}

char* s21_strrchr(const char* str, int c) {
    const char* result = NULL;
    size_t len = s21_strlen(str);
    for (int i = (int)len; i >= 0; i--) {
        int code = *(str + i);
        if (code == c) {
            result = str + i;
            break;
        }
    }
    return (char*)result;
}

size_t s21_strspn(const char* str1, const char* str2) {
    int i, j;
    for (i = 0; str1[i] != '\0'; i++) {
        for (j = 0; str2[j] != '\0'; j++) {
            if (str2[j] == str1[i])
                break;
        }
        if (!str2[j])
            break;
    }
    return (size_t)i;
}

char* s21_strstr(const char* haystack, const char* needle) {
    char* res = NULL;
    size_t len1 = s21_strlen(haystack);
    size_t len2 = s21_strlen(needle);
    if (len1 == 0 && len2 == 0)
        res = (char*)haystack;
    if (!res) {
        int counter = 0;
        for (int i = 0; *(haystack + i) != '\0'; i++) {
            if (*(haystack + i) == *needle) {
                for (int j = 0; *(needle + j) != '\0'; j++) {
                    if (*(haystack + i + j) == *(needle + j))
                        counter++;
                }
            }
            if (counter == (int)len2) {
                res = (char*)haystack + i;
                break;
            }
        }
    }
    return res;
}

char* s21_strtok(char* str, const char* delim) {
    char *sbegin, *send;
    static char *ssave = "";
    sbegin = str ? str : ssave;
    sbegin += s21_strspn(sbegin, delim);
    if (*sbegin == '\0') {
        ssave = "";
        return NULL;
    }
    send = sbegin + s21_strcspn(sbegin, delim);
    if (*send != '\0')
        *send++ = '\0';
    ssave = send;
    return (sbegin);
}

void* s21_memchr(const void* str, int c, size_t n) {
    unsigned char* arr = (unsigned char*)str;
    unsigned char chr = (unsigned char)c;
    char* out = NULL;

    for (size_t i = 0; i < n; i++) {
        if (arr[i] == chr) {
            out = (char*)str + i;
            break;
        }
    }
    return (void*)out;
}

int s21_memcmp(const void* str1, const void* str2, size_t n) {
    unsigned char* s1 = (unsigned char*)str1;
    unsigned char* s2 = (unsigned char*)str2;
    int out = 0;

    for (size_t i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            out = s1[i] - s2[i];
            break;
        }
    }

    return out;
}

void* s21_memcpy(void* dest, const void* src, size_t n) {
    unsigned char* destination = (unsigned char*)dest;
    unsigned char* source = (unsigned char*)src;

    for (size_t i = 0; i < n; i++) {
        destination[i] = source[i];
    }

    return destination;
}

void* s21_memmove(void* dest, const void* src, size_t n) {
    unsigned char* destination = (unsigned char*)dest;
    unsigned char* source = (unsigned char*)src;

    if (&source[0] > &destination[0]) {
        dest = s21_memcpy(dest, src, n);
    } else {
        while (n > 0) {
            destination[n - 1] = source[n - 1];
            n--;
        }
    }
    return dest;
}

void* s21_memset(void* str, int c, size_t n) {
    unsigned char* arr = str;

    while (n >= 1) {
        arr[n - 1] = (unsigned char)c;
        n--;
    }

    return arr;
}

char* s21_strcat(char* dest, const char* src) {
    size_t len = s21_strlen(dest);

    while (src[0] != '\0') {
        dest[len] = (char)src[0];
        len++;
        src++;
    }
    dest[len] = '\0';

    return dest;
}

char* s21_strncat(char* dest, const char* src, size_t n) {
    size_t len = s21_strlen(dest);

    for (size_t i = 0; *(src + i) != '\0' && i < n; i++) {
        dest[len] = (char)src[i];
        len++;
    }
    dest[len] = '\0';

    return dest;
}

int is_char_in_string(char current, const char* delim) {
    int res = 0;
    for (int i = 0; *(delim + i) != '\0'; i++) {
        if (current == delim[i]) {
            res = 1;
            break;
        }
    }
    return res;
}

char* s21_strncpy(char* dest, const char* src, size_t n) {
    char* ptr = dest;
    size_t i = 0;
    while (*src != '\0' && i < n) {
        *dest = *src;
        dest++;
        src++;
        i++;
    }
    *dest = '\0';
    return ptr;
}

char* s21_strchr(const char* str, int c) {
    const char* result = NULL;
    size_t len = s21_strlen(str);
    for (int i = 0; i <= (int)len; i++) {
        int code = *(str + i);
        if (c == code) {
            result = str + i;
            break;
        }
    }
    return (char*)result;
}

int s21_strcmp(const char* str1, const char* str2) {
    size_t len1 = s21_strlen(str1);
    size_t len2 = s21_strlen(str2);
    size_t i = 0;

    if (len1 > len2) {
        len1 = len2;
    }

    while (i < len1 && *str1 == *str2) {
        str1++;
        str2++;
        i++;
    }
    int result1 = (int)(*str1) - (int)(*str2);
    return result1;
}

int s21_strncmp(const char* str1, const char* str2, size_t n) {
    int result = 0;
    while (n-- > 0) {
      unsigned char u1 = (unsigned char) *str1++;
      unsigned char u2 = (unsigned char) *str2++;
      if (u1 != u2) {
        result = u1 - u2;
        break;
      }
    }
    return result;
}

size_t s21_strcspn(const char* str1, const char* str2) {
    size_t i = 0;
    int len = s21_strlen(str1);
    while (is_char_in_string(str1[i], str2) == 0 && (int)i < len) {
        i++;
    }
    return i;
}

char* s21_strcpy(char* dest, const char* src) {
    char* ptr = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return ptr;
}

char* s21_strerror(int num) {
    char* res;
    const char* errors[] = MAKERLIST;
    if (num >= 0 && num < CAPACITY) {
       res = (char*)errors[num];
    } else {
        static char temp[100];
        s21_sprintf(temp, "%s%d", (char*)STR_ERROR, num);
        res = (char*)temp;
    }
    return res;
}

void* s21_to_upper(const char* str) {
    char* new_str = NULL;
    if (str) {
        int len = s21_strlen(str);
        new_str = (char*)malloc((len + 1) * sizeof(char));
        if (new_str) {
            for (int i = 0; i < len; i++) {
                if ((int)str[i] >= 97 && (int)str[i] <= 122) {
                    new_str[i] = (char)((int)str[i] - 32);
                } else {
                    new_str[i] = str[i];
                }
            }
            new_str[len] = '\0';
        }
    }
    return new_str;
}

void* s21_to_lower(const char* str) {
    char* new_str = NULL;
    if (str) {
        int len = s21_strlen(str);
        new_str = (char*)malloc((len + 1) * sizeof(char));
        if (new_str) {
            for (int i = 0; i < len; i++) {
                if ((int)str[i] >= 65 && (int)str[i] <= 90) {
                    new_str[i] = (char)((int)str[i] + 32);
                } else {
                    new_str[i] = str[i];
                }
            }
            new_str[len] = '\0';
        }
    }
    return new_str;
}

void* s21_insert(const char* src, const char* str, size_t start_index) {
    char* new_str = NULL;
    if (src && str && (start_index <= s21_strlen(src))) {
        int i = 0;
        size_t len_src = s21_strlen(src);
        size_t len_str = s21_strlen(str);
        size_t size = len_src + len_str;
        new_str = (char*)malloc((size + start_index + 1) * sizeof(char));
        for (i = 0; i < start_index; i++) {
            new_str[i] = src[i];
        }
        for (i = 0; i < len_str; i++) {
            new_str[start_index + i] = str[i];
        }
        for (i = 0; i < len_src; i++) {
            new_str[start_index + len_str + i] = src[start_index + i];
        }
        new_str[size] = '\0';
    }
    return new_str;
}

void* s21_trim(const char* src, const char* trim_chars) {
    char* new_str = NULL;
    if (src && trim_chars) {
        int len = s21_strlen(src);
        int start_cutoff = 0;
        int end_cutoff = len - 1;
        int size = 0;
        int counter = 0;

        new_str = (char*)malloc((len + 1 )* sizeof(char));

        if (new_str) {
            while (is_char_in_string(src[counter], trim_chars) == 1) {
                counter++;
            }
            start_cutoff = counter;

            counter = len - 1;
            while (is_char_in_string(src[counter], trim_chars) == 1 && counter >= 0) {
                counter--;
            }
            end_cutoff = counter;
            size = end_cutoff - start_cutoff + 1;
            if (size > 0) {
                for (counter = 0; counter < size; counter++) {
                    new_str[counter] = src[start_cutoff + counter];
                }
                new_str[size] = '\0';
            } else {
                *new_str = '\0';
            }
        }
    }
    return new_str;
}

int s21_sscanf(const char* str, const char* format, ...) {
    int res = 0, no_assign = 0, width = -1, base = 10, read_length = 0;
    char lflag = '\0';
    va_list args;
    va_start(args, format);
    char* temp = (char*)malloc((int)(s21_strlen(str) + 1) * sizeof(char));

    while (*format != '\0' || *str != '\0') {
        int n = skip_delimeters(&format);
        if (n)
            read_length += skip_delimeters(&str);
        if (*format == '%') {
            format++;
            width_handler(&format, &width, &no_assign);
            lenght_handler(&format, &lflag);
            int spec = get_spec(&format, str, &base);
            if (spec != 9)
                read_length += skip_delimeters(&str);
            temp = get_string(temp, str, spec, &width);
            if (width > 0 && !no_assign && *temp != '\0')
                write_to_var(spec, base, &args, temp, lflag, res, width);
            if (spec == 9) {
                int* p = va_arg(args, int*);
                *p = read_length;
            }
            if (width > 0) {
                read_length += width;
                if (!no_assign && spec != 10)
                    res++;
                str += width;
            }
            if ((width <= 0) && (spec != 9)) break;
            width = -1, no_assign = spec = 0;
        } else {
            if (*str != *format) {
                break;
            } else { str++; format++; read_length++; }
        }
    }
    free(temp);
    va_end(args);
    return res;
}

int skip_delimeters(const char** str) {
    int res = 0;
    while (isspace(**str)) {
        (*str)++;
        res++;
    }
    return res;
}

void write_to_var(int spec, int base, va_list* list, char* string, char lflag, int count, int width) {
    if (spec >= 1 && spec <= 5) {
        write_int(spec, base, list, string, lflag);
    } else if (spec == 6 || spec == 7) {
        write_str(spec, string, list, width);
    } else if (spec == 8) {
        write_pointer(base, list, string);
    } else if (spec == 9) {
        int* p = va_arg(*list, int*);
        *p = count;
    } else if (spec >= 11 && spec <= 15) {
        write_float(list, string, lflag);
    }
}

void write_float(va_list* list, char* string, char lflag) {
    long double temp = strtold(string, NULL);
    if (lflag == 'l') {
        double* p = va_arg(*list, double*);
        *p = (double)temp;
    } else if (lflag == 'L') {
        long double* p = va_arg(*list, long double*);
        *p = temp;
    } else {
        float* p = va_arg(*list, float*);
        *p = (float)temp;
    }
}

void write_int(int spec, int base, va_list* list, char* string, char lflag) {
    if (spec == 1) {
        long temp = strtol(string, NULL, base);
        if (lflag == 'h') {
            short int* p = va_arg(*list, short int*);
            *p = (short int)temp;
        } else if (lflag == 'l') {
            long int* p = va_arg(*list, long int*);
            *p = temp;
        } else {
            int* p = va_arg(*list, int*);
            *p = (int)temp;
        }
    } else if (spec == 2 || spec == 3 || spec == 4 || spec == 5) {
        unsigned long utemp = strtoul(string, NULL, base);
        if (lflag == 'h') {
            short unsigned int* p = va_arg(*list, short unsigned int*);
            *p = (short int)utemp;
        } else if (lflag == 'l') {
            long unsigned int* p = va_arg(*list, long unsigned int*);
            *p = utemp;
        } else {
            unsigned int* p = va_arg(*list, unsigned int*);
            *p = utemp;
        }
    }
}

void write_str(int spec, const char* string, va_list* list, int width) {
    if (spec == 6) {
        char* p = va_arg(*list, char*);
        if (width > 1) {
            s21_memcpy(p, string, width);
        } else {
            *p = *string;
        }
    } else if (spec == 7) {
        char* p = va_arg(*list, char*);
        s21_strncpy(p, string, width);
    }
}

void write_pointer(int base, va_list* list, char* string) {
    unsigned long long temp = strtoull(string, NULL, base);
    void** p = va_arg(*list, void**);
    *p = (void*)temp;
}

char* get_string(char res[], const char* str, int spec, int* width) {
    if (res) {
        if ((spec >= 1 && spec <= 5) || spec == 8 || spec == 16) {
            get_string_int(res, str, spec, width);
        } else if (spec == 6) {
            if (*width > 1) {
                get_string_str(res, str, width);
            } else {
                *width = 1;
                res[0] = *str;
                res[1] = '\0';
            }
        } else if (spec == 10) {
            if (*str == '%') {
                *width = 1;
                res[0] = *str;
                res[1] = '\0';
            }
        } else if (spec == 7) {
            get_string_str(res, str, width);
        } else if (spec >= 11 && spec <= 15) {
            get_string_float(res, width, str);
        }
    }
    return res;
}

void get_string_int(char res[], const char* str, int spec, int* width) {
    int counter = 0;
    if (spec == 1 || spec == 3) {
        get_exact_width_int(str, &counter, 57, 48, *width);
    } else if (spec == 2) {
        get_exact_width_int(str, &counter, 55, 48, *width);
    } else if (spec == 8 || spec == 4 || spec == 5) {
        if (*str == '-' || *str == '+') counter++;
        if ((*(str + counter) == '0' && *(str + counter + 1) == 'X')
            || (*(str + counter) == '0' && *(str + counter + 1) == 'x'))
            counter += 2;
        get_exact_width_hex(str, &counter, *width);
    }
    *width = counter;
    s21_strncpy(res, str, counter);
}

void get_exact_width_int(const char* str, int* counter, int right, int left, int width) {
    if (*str == '-' || *str == '+') (*counter)++;
    if (width == -1) {
        while ((*(str + *counter) >= left && *(str + *counter) <= right)) {
            (*counter)++;
        }
    } else {
        while ((*(str + *counter) >= left && *(str + *counter) <= right) && (*counter < width)) {
            (*counter)++;
        }
    }
    if (*counter == 1 && (*str == '-' || *str == '+')) (*counter) = 0;
}

void get_exact_width_hex(const char* str, int* counter, int width) {
    if (*str == '-') (*counter)++;
    if (width == -1) {
        while ((isdigit(*(str + *counter)) ||
            (*(str + *counter) >= 'A' && *(str + *counter) <= 'F') ||
            ((*(str + *counter) >= 'a') && (*(str + *counter) <= 'f')))) {
            (*counter)++;
        }
    } else {
        while ((isdigit(*(str + *counter)) ||
            (*(str + *counter) >= 'A' && *(str + *counter) <= 'F') ||
            ((*(str + *counter) >= 'a') && (*(str + *counter) <= 'f'))) && *counter < width) {
            (*counter)++;
        }
    }
    if (*counter == 1 && *str == '-') (*counter) = 0;
}

size_t read_float(int width, const char* str) {
    size_t counter = 0;
    if (*str == '-' || *str == '+') counter++;
    if (width == -1) {
        while (isdigit(*(str + counter)))
            counter++;
        if (*(str + counter) == '.') {
            counter++;
            while (isdigit(*(str + counter)))
                counter++;
        }
    } else {
        while (isdigit(*(str + counter)) && (int)counter < width)
            counter++;
        if (*(str + counter) == '.' && (int)counter < width)
            counter++;
        while (isdigit(*(str + counter)) && (int)counter < width) {
            counter++;
        }
    }
    return counter;
}

void get_string_float(const char res[], int* width, const char* str) {
    size_t counter = 0;
    counter = read_float(*width, str);
    if (*(str + counter) == 'e' || *(str + counter) == 'E') {
        counter++;
        if (*str == '-' || *str == '+') counter++;
        if (*width == -1) {
            while (isdigit(*(str + counter)))
                counter++;
        } else {
            while (isdigit(*(str + counter)) && (int)counter < *width)
                counter++;
        }
    } else if (s21_strncmp(str, "infinity", 8) == 0 || (s21_strncmp(str, "-infinity", 9) == 0)) {
        counter += 8;
    } else if (s21_strncmp(str, "inf", 3) == 0 || s21_strncmp(str, "-inf", 4) == 0) {
        counter += 3;
    }
    *width = counter;
    s21_strncpy((char*)res, str, *width);
}

void get_string_str(char res[], const char* str, int* width) {
    int exact_len = 0;
    if (*width == -1) {
        while (*(str + exact_len) != ' ' && *(str + exact_len) != '\0')
            exact_len++;
    } else {
        while ((*(str + exact_len) != ' ' && *(str + exact_len) != '\0') && exact_len < *width)
            exact_len++;
    }
    *width = exact_len;
    s21_strncpy(res, str, *width);
}

int get_spec(const char** format, const char* str, int* base) {
    int res = 0;
    res = other_handler(format, base);
    if (!res)
        res = char_handler(format);
    if (!res)
        res = float_handler(format);
    if (!res)
        res = base_int_handler(format, str, base);
    return res;
}

int other_handler(const char** format, int* base) {
    int res = 0;
    if (**format == 'p') {
        res = 8;
        *base = 16;
    } else if (**format == 'n') {
        res = 9;
    } else if (**format == '%') {
        res = 10;
    }
    if (res)
        (*format)++;
    return res;
}

int char_handler(const char** format) {
    int res = 0;
    if (**format == 'c')
        res = 6;
    else if (**format == 's')
        res = 7;
    if (res)
        (*format)++;
    return res;
}

int float_handler(const char** format) {
    int res = 0;
    if (**format == 'e')
        res = 11;
    else if (**format == 'E')
        res = 12;
    else if (**format == 'f')
        res = 13;
    else if (**format == 'g')
        res = 14;
    else if (**format == 'G')
        res = 15;
    if (res)
        (*format)++;
    return res;
}

int base_int_handler(const char** format, const char* str, int* base) {
    int res = 0;
    if (**format == 'd') {
        *base = 10;
        res = 1;
    } else if (**format == 'i') {
        res = get_base_i(str, base);
    } else  if (**format == 'o') {
        *base = 8;
        res = 2;
    } else if (**format == 'u') {
        *base = 10;
        res = 3;
    } else if (**format == 'x') {
        *base = 16;
        res = 4;
    } else if (**format == 'X') {
        *base = 16;
        res = 5;
    }
    if (res)
        (*format)++;
    return res;
}

int get_base_i(const char* str, int* base) {
    int res = 1;
    if (*str == '+' || *str == '-') {
        if ((*(str + 1) == '0') && (*(str + 2) == 'x')) {
            res = 4;
            *base = 16;
        } else if (*(str + 1) && *(str + 2) == 'X') {
            res = 5;
            *base = 16;
        } else if (*(str + 1) == '0') {
            res = 2;
            *base = 8;
        }
    } else {
        if ((*str == '0') && (*(str + 1) == 'x')) {
            res = 4;
            *base = 16;
        } else if (*str == '0' && *(str + 1) == 'X') {
            res = 5;
            *base = 16;
        } else if (*str == '0') {
            res = 2;
            *base = 8;
        }
    }
    return res;
}

void lenght_handler(const char** str, char* lflag) {
    if ((*lflag = is_lenght(*(*str))))
        (*str)++;
}

void width_handler(const char** str, int* width, int* no_assign) {
    if (is_width(**str) == -1) {
        *no_assign = 1;
        (*str)++;
    }
    if (is_width(**str) == 1) {
        char tmp[100];
        const char* temp;
        for (temp = *str; isdigit(**str); (*str)++) {}
        s21_strncpy(tmp, temp, *str - temp);
        tmp[*str - temp] = '\0';
        *width = atoi(tmp);
    }
}

char is_lenght(char c) {
    char res = '\0';
    if (c == 'L' || c == 'h' || c == 'l')
        res = c;
    return res;
}

int is_width(char c) {
    int res = 0;
    if (c == '*')
        res = -1;
    if (isdigit(c))
        res = 1;
    return res;
}

int s21_sprintf(char *str, const char *format, ...) {
    int i = 0;
    char *flags = (char*)malloc(6 * sizeof(char)), length = -1;
    va_list args;
    va_start(args, format);
    char *parsed_str = (char*)malloc(MAX * sizeof(char));
    *str = '\0';
    for (char *ch = (char*)format; *ch; ch++) {
        if (*ch != '%') {
            str[i] = *ch;
            str[i + 1] = '\0';
            i++;
        } else if (!s21_strchr("cdieEfgGosuxXpn%", *ch)) {
            continue;
        } else {
            int width = -1, prec = -1, spec = -1, base = 10, to_upper = -1;
            ch++;
            try_set_flag(&flags, &ch);
            width = try_set_width(&ch, args);
            prec = try_set_prec(&ch, args);
            length = try_set_length(&ch);
            spec = set_spec(ch, length);
            base = set_base(ch);
            to_upper = set_case(ch);
            to_string(&parsed_str, *ch, spec, args, base, &prec, str);
            if (parsed_str != NULL) {
                if (*ch != 'n') add_flag(&parsed_str, *ch, flags, width, prec);
                if (to_upper > 0) set_up_case(&parsed_str, to_upper);
                s21_strcpy(str + i, parsed_str);
                i += s21_strlen(parsed_str);
            }
        }
    }
    va_end(args);
    free(flags);
    free(parsed_str);
    return i;
}

void try_set_flag(char **flags, char **ch) {
    int i = 0;
    for (i = 0; i < 5; i++) {
        *(*flags + i) = -1;
    }
    *(*flags + i) = '\0';
    int j = 0;
    while (**ch == 32 || **ch == 35 || **ch == 43 || **ch == 45 || **ch == 48) {
        *(*flags + j) = **ch;
        j++;
        (*ch)++;
    }
}

int try_set_width(char **ch, va_list args) {
    int res = -1, i = 0;
    char temp[1000];
    if (**ch == 42) {
        res = va_arg(args, int);
        (*ch)++;
    } else if (**ch >= 48 && **ch <= 57) {
        while (**ch >= 48 && **ch <= 57) {
            temp[i] = **ch;
            i++;
            (*ch)++;
        }
        temp[i] = '\0';
        res = atoi(temp);
    }
    return res;
}

int try_set_prec(char **ch, va_list args) {
    int res = -1;
    if (**ch == 46) {
        char temp[1000];
        int i = 0;
        (*ch)++;
        if (**ch == 42) {
            res = va_arg(args, int);
            (*ch)++;
        } else if (**ch >= 48 && **ch <= 57) {
            while (**ch >= 48 && **ch <= 57) {
                temp[i] = **ch;
                i++;
                (*ch)++;
            }
            temp[i] = '\0';
            res = atoi(temp);
        }
    }
    return res;
}

char try_set_length(char **ch) {
    char res = -1;
    if (**ch == 76 || **ch == 104 || **ch == 108) {
        res = **ch;
        (*ch)++;
    }
    return res;
}

int set_spec(char *ch, char length) {
    int res = -1;
    if (*ch == 'c' || *ch == 's') {
        if (*ch == 'c') res = 1;
        else if (*ch == 's') res = 2;
    } else if (*ch == 'd' || *ch == 'i') {
        if (length == 'h') res = 3;
        else if (length == 'l') res = 4;
        else
            res = 5;
    } else if (*ch == 'f' || *ch == 'e' || *ch == 'E' ||*ch == 'g' || *ch == 'G') {
        if (length == 'L') res = 6;
        else
            res = 7;
    } else if (*ch == 'u' || *ch == 'o' || *ch == 'x' || *ch == 'X') {
        if (length == 'h') res = 8;
        else if (length == 'l') res = 9;
        else
            res = 10;
    } else if (*ch == 'p') {
        res = 11;
    } else if (*ch == 'n') {
        if (length == 'h') res = 3;
        else if (length == 'l') res = 4;
        else
            res = 5;
    } else if (*ch == '%') {
        res = 12;
    }
    return res;
}

int set_base(char *ch) {
    int type = 10;
    if (*ch == 'o') {
        type = 8;
    } else if (*ch == 'x' || *ch == 'X') {
        type = 16;
    }
    return type;
}

int set_case(char *ch) {
    int res = -1;
    if (*ch >= 65 && *ch <= 90) {
        res = 1;
    }
    return res;
}

void to_string(char **str, char ch, int spec, va_list args, int base, int *prec, const char *prsd) {
    if (spec == 5 || spec == 10) {
        int_to_string(str, spec, ch, args, base, *prec, prsd);
    } else if (spec == 3 || spec == 8) {
        sint_to_string(str, spec, ch, args, base, *prec, prsd);
    } else if (spec == 4 || spec == 9) {
        lint_to_string(str, spec, ch, args, base, *prec, prsd);
    } else if (spec == 6 || spec == 7) {
        d_to_string(str, spec, ch, args, prec);
    } else if (spec == 1 || spec == 2 || spec == 12) {
        ch_to_string(str, spec, args, *prec);
    } else if (spec == 11) {
        vp_to_string(str, args);
    }
}

void int_to_string(char **str, int num, char ch, va_list args, int base, int prec, const char *prsd) {
    switch (num) {
        case 5: {
            if (ch == 'n') {
                int *temp = va_arg(args, int*);
                *temp = (int)s21_strlen(prsd);
                **str = '\0';
            } else {
                int temp = va_arg(args, int);
                check_base(str, base, temp, prec);
            }
            break; }
        case 10: {
            unsigned int temp = va_arg(args, unsigned int);
            check_base(str, base, temp, prec);
            break; }
    }
}

void sint_to_string(char **str, int num, char ch, va_list args, int base, int prec, const char *prsd) {
    switch (num) {
        case 3: {
            if (ch == 'n') {
                short int *temp = va_arg(args, short int*);
                *temp = (short int)s21_strlen(prsd);
                **str = '\0';
            } else {
                short int temp = va_arg(args, int);
                check_base(str, base, temp, prec);
            }
            break; }
        case 8: {
            unsigned short int temp = va_arg(args, int);
            check_base(str, base, temp, prec);
            break; }
    }
}

void lint_to_string(char **str, int num, char ch, va_list args, int base, int prec, const char *prsd) {
    switch (num) {
        case 4: {
            if (ch == 'n') {
                long int *temp = va_arg(args, long int*);
                *temp = (long int)s21_strlen(prsd);
                **str = '\0';
            } else {
                long int temp = va_arg(args, long int);
                check_base(str, base, temp, prec);
            }
            break; }
        case 9: {
            unsigned long int temp = va_arg(args, unsigned long int);
            check_base(str, base, temp, prec);
            break; }
    }
}

void check_base(char **str, long int base, int num, int prec) {
    char *temp = (char*)malloc(MAX * sizeof(char));
    if (base == 16) {
        dec_to_hex(&temp, num);
    } else if (base == 8) {
        num = dec_to_oct(num);
        i_to_a(&temp, num);
    } else {
        i_to_a(&temp, num);
    }
    if ((int)s21_strlen(temp) < prec) add_zeroes(&temp, prec, 0, 1);
    s21_strcpy(*str, temp);
    free(temp);
}

void dec_to_hex(char **str, int num) {
    char *hex = (char*)malloc(20 * sizeof(char));
    int i = 0;
    while (num > 0) {
        switch (num % 16) {
            case 10: *(hex + i) = 'a'; break;
            case 11: *(hex + i) = 'b'; break;
            case 12: *(hex + i) = 'c'; break;
            case 13: *(hex + i) = 'd'; break;
            case 14: *(hex + i) = 'e'; break;
            case 15: *(hex + i) = 'f'; break;
            default: *(hex + i) = (num % 16) + 0x30;
        }
        num /= 16;
        i++;
    }
    *(hex + i) = '\0';
    str_reverse(&hex);
    s21_strcpy(*str, hex);
    free(hex);
}

void str_reverse(char **str) {
    int len = s21_strlen(*str);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        int c = *(*str + i);
        *(*str + i) = *(*str + j);
        *(*str + j) = c;
    }
}

int dec_to_oct(int num) {
    int oct = 0, val = 1;
    while (num != 0) {
        oct += (num % 8) * val;
        num /= 8;
        val *= 10;
    }
    return oct;
}

void i_to_a(char **str, long int num) {
    char *temp;
    int digit_count = 0;
    if (num < 0) {
        num = -num;
        digit_count++;
    }
    digit_count += digits_count(num);
    temp = malloc((digit_count + 2) * sizeof(char));
    temp[digit_count] = '\0';
    if (num == 0) {
        *temp = '0';
        *(temp + 1) = '\0';
    }
    while (num > 0) {
        *(temp + (digit_count - 1)) = num % 10 + '0';
        num /= 10;
        digit_count--;
    }
    if (digit_count == 1) *temp = '-';
    s21_strcpy(*str, temp);
    free(temp);
}

int digits_count(long int num) {
    int digit_count = 0;
    if (num < 0) num = -num;
    while (num > 0) {
        digit_count++;
        num /= 10;
    }
    return digit_count;
}

void d_to_string(char **str, int num, char ch, va_list args, int *prec) {
    switch (num) {
        case 6: {
            long double temp = va_arg(args, long double);
            d_conv(str, temp, ch, prec);
            break; }
        case 7: {
            double temp = va_arg(args, double);
            d_conv(str, temp, ch, prec);
            break; }
    }
}

void d_conv(char **str, double num, char ch, int *prec) {
    int true_prec = *prec;
    if (*prec < 0) *prec = 6;
    if (ch == 'f') {
        f_style_conversion(str, num, *prec);
    } else if (ch == 'e' || ch == 'E') {
        d_to_sci_not(str, num, *prec);
    } else if (ch == 'g' || ch == 'G') {
        int exp = log10(fabs(num));
        if (*prec > exp && exp > -4) {
            int tmp_prec = *prec - (exp + 1);
            f_style_conversion(str, num, tmp_prec);
        } else {
            int tmp_prec = *prec - 1;
            d_to_sci_not(str, num, tmp_prec);
        }
        *prec = true_prec;
    }
}

void f_style_conversion(char **str, long double num, int prec) {
    int pt, sg;
    f_to_a(str, num, prec, &pt, &sg);
    char *temp = (char*)malloc(20 * sizeof(char));
    *temp = '\0';
    if (num != INFINITY && !isnan(num)) {
        if (sg) s21_strcpy(temp, "-");
        if (!pt && num < 0) s21_strcat(temp, "0");
        else if (pt) s21_strncat(temp, *str, pt);
        else
            s21_strncat(temp, *str, s21_strlen(*str));
        if (prec > 0) {
            s21_strcat(temp, ".");
            s21_strncat(temp, *str + pt, prec);
        }
        s21_strcpy(*str, temp);
        free(temp);
        add_zeroes(str, prec, pt ? pt : 1, 0);
    }
}

void f_to_a(char **str, long double num, int prec, int *pt, int *sg) {
    *sg = 0;
    if (num < 0) {
        *sg = 1;
        num = -num;
    }
    char *tmp0 = (char*)malloc(MAX * sizeof(char));
    *tmp0 = '\0';
    long int i_p;
    int i = digits_count(num), f = 0;
    if (num > EPSILON) i_p = (long int)num;
    else
        i_p = 0;
    long double f_p = num - (long double)i_p;
    *pt = i;
    i_to_a(&tmp0, i_p);
    if (prec > 0 && f_p >= EPSILON) {
        char *tmp1 = (char*)malloc(20 * sizeof(char));
        *tmp1 = '\0';
        do {
            f_p = f_p * pow(10, prec);
            if (f_p <= 1 && f_p >= -1) f += prec;
        } while (((long double)((f_p * 0.000002) - (long double)lroundl(f_p))
            >= EPSILON) && fabs(f_p) <= powl(10, prec));
        i_to_a(&tmp1, (long int)lroundl(f_p));
        int d_c_f_p = digits_count(lroundl(f_p));
        add_zeroes(&tmp1, prec, f, 1);
        s21_strcat(tmp0, tmp1);
        free(tmp1);
    }
    s21_strcpy(*str, tmp0);
    free(tmp0);
}

void cut_zeroes(char **str) {
    int len = s21_strlen(*str);
    for (int i = len - 1; i > 0; i--) {
        if (*(*str + i) != '0' || *(*str + i) == '.') {
            if (*(*str + i) == '.') len--;
            break;
        } else {
            len--;
        }
    }
    *(*str + len) = '\0';
}

void add_zeroes(char **str, char prec, int exp, int are_pre) {
    int len = s21_strlen(*str);
    if (prec > 0) {
        if (are_pre && (len < (prec + exp + 1))) {
            if (**str == '-') len--;
            int diff = (prec + exp) - len;
            char *temp = (char*)malloc((prec + exp + 2) * sizeof(char));
            int i = 0;
            if (**str == '-') {
                *temp = '-';
                *(temp + 1) = '\0';
                i++;
                diff++;
            } else { *temp = '\0'; }
            for ( ; i < diff; i++) *(temp + i) = '0';
            *(temp + i) = '\0';
            if (**str == '-') s21_strcat(temp, *str + 1);
            else
                s21_strcat(temp, *str);
            s21_strcpy(*str, temp);
            free(temp);
        } else {
            int val = s21_strchr(*str, '.') ? (prec + exp + 1) : (prec + exp);
            val += **str == '-' ? 1 : 0;
            for ( ; len < val; len++) *(*str + len) = '0';
            *(*str + len) = '\0';
        }
    }
}

void d_to_sci_not(char **str, long double num, int prec) {
    int pt, sg, exp, i = 0;
    f_to_a(str, num, prec + 1, &pt, &sg);
    int len = s21_strlen(*str);
    char *temp = (char*)malloc(MAX * sizeof(char));
    *temp = '\0';
    if (len == 1 && **str == '0') {
        if (sg) s21_strcpy(*str, "-0\0");
        s21_strcat(*str, ".\0");
        add_zeroes(str, prec, 1, 0);
        s21_strcat(*str, "e+00\0");
    } else if (num != INFINITY && !isnan(num)) {
        if (sg) s21_strcpy(temp, "-");
        if (**str != '0') { exp = --pt;
        } else {
            for ( ; i < len; i++) { if (*(*str + i) != '0') { break; } }
            exp = -i;
        }
        s21_strncat(temp, *str + i, 1);
        if (prec > 1) s21_strncat(temp, ".", 1);
        s21_strncat(temp, *str + i + 1, prec);
        *(temp + (sg ? 3 : 2) + prec) = '\0';
        add_zeroes(&temp, prec, 1, 0);
        s21_strncat(temp, "e", 1);
        if (exp < 0) s21_strcat(temp, "-");
        else
            s21_strcat(temp, "+");
        char *texp = (char*)malloc(5 * sizeof(char));
        i_to_a(&texp, fabs(exp));
        if (exp < 10 && exp > -10) s21_strcat(temp, "0");
        s21_strcat(temp, texp);
        free(texp);
        s21_strcpy(*str, temp);
    }
    free(temp);
}

void ch_to_string(char **str, int num, va_list args, int prec) {
    switch (num) {
        case 1: {
            char temp = (char)va_arg(args, int);
            **str = temp;
            *(*str + 1) = '\0';
            break; }
        case 2: {
            const char *temp = va_arg(args, const char*);
            if (prec > 0 && prec < (int)s21_strlen(temp)) {
                s21_strncpy(*str, temp, prec);
                *(*str + prec) = '\0';
            } else {
                s21_strcpy(*str, temp);
            }
            break; }
        case 12: {
            **str = '%';
            *(*str + 1) = '\0';
            break; }
    }
}

void vp_to_string(char **str, va_list args) {
    void *temp = va_arg(args, void*);
    address_to_str(str, (unsigned long)temp, 16);
    add_prefix(str, 'x');
}

void address_to_str(char **str, uintmax_t num, int base) {
    s21_size_t i = 1;
    uintmax_t val = num;
    while ((val /= base) >= 1) i++;
    char *temp = (char*)malloc(sizeof(char) * (i + 1));
    *(temp + i) = '\0';
    while (i-- > 0) {
        int rem = num % base;
        if (rem > 9) *(temp + i) = (rem - 10) + 'a';
        else
            *(temp + i) = rem + '0';
        num /= base;
    }
    s21_strcpy(*str, temp);
    free(temp);
}

void add_prefix(char **str, char pref) {
    char *temp = (char*)malloc((3 + s21_strlen(*str)) * sizeof(char));
    *temp = '\0';
    if (pref == '0') {
        s21_strcpy(temp, "0");
    } else if (pref == 'x') {
        s21_strcpy(temp, "0x");
    } else if (pref == ' ') {
        if (*str[0] != '-') {
            s21_strcpy(temp, " ");
        }
    } else if (pref == '+') {
        if (*str[0] != '-') {
            s21_strcpy(temp, "+");
        }
    }
    s21_strcat(temp, *str);
    s21_strcpy(*str, temp);
    free(temp);
}

void add_flag(char **str, char ch, char *flags, int width, int prec) {
    width = width > 0 ? width : 0;
    char *temp = (char*)malloc((s21_strlen(*str) + 3 + width) * sizeof(char));
    s21_strcpy(temp, *str);
    int len = s21_strlen(flags), has_point = s21_strchr(temp, '.') ? 1 : 0;
    if (s21_strchr(flags, '#')) {
        if (ch == 'o' && **str != '0') { add_prefix(&temp, '0');
        } else if (ch == 'x' || ch == 'X') { add_prefix(&temp, 'x');
        } else if ((ch == 'f' || ch == 'e' || ch == 'E') && !s21_strchr(temp, '.')) {
            int len = (int)s21_strlen(temp);
            *(temp + len) = '.';
            *(temp + len + 1) = '\0';
        } else if (ch == 'g' || ch == 'G') {
            prec = s21_strlen(temp) - (dig_before_point(temp) + has_point);
        }
    } else if (!s21_strchr(flags, '#') && (ch == 'g' || ch == 'G')) {
        cut_zeroes(&temp);
        prec = s21_strlen(temp) - (dig_before_point(temp) + has_point);
    }
    if (s21_strchr(flags, ' ')) add_prefix(&temp, ' ');
    if (s21_strchr(flags, '+')) add_prefix(&temp, '+');
    if (prec < 0) prec = 0;
    has_point = s21_strchr(temp, '.') ? 1 : 0;
    if (((ch == 's' || ch == 'c') && width > s21_strlen(temp)) ||
        (width > 0 && width > prec + has_point + dig_before_point(temp))) {
        if (s21_strchr(flags, '0')) add_width(&temp, ch, '0', width);
        else if (s21_strchr(flags, '-')) add_width(&temp, ch, '-', width);
        else
            add_width(&temp, ch, -1, width);
    }
    s21_strcpy(*str, temp);
    free(temp);
}

void add_width(char **str, char ch, char flag, int width) {
    char *temp = (char*)malloc((width + 1) * sizeof(char));
    int len = s21_strlen(*str), i = 0;
    if (**str == '-') {
        *temp = '-';
        *(temp + 1) = '\0';
        if (width < len) len--;
    } else {
        *temp = '\0';
    }
    if (width > len) {
        int diff = width - len;
        if (flag == '0') {
            if (**str == '-') {
                i++;
                diff++;
            }
            for ( ; i < diff; i++) *(temp + i) = '0';
            *(temp + i) = '\0';
            if (**str == '-') s21_strcat(temp, *str + 1);
            else
                s21_strcat(temp, *str);
            s21_strcpy(*str, temp);
        } else if (flag == '-') {
            s21_strcpy(temp, *str);
            for (i = len; i < width; i++) *(temp + i) = ' ';
            *(temp + i) = '\0';
            s21_strcpy(*str, temp);
        } else {
            for ( ; i < diff; i++) *(temp + i) = ' ';
            *(temp + i) = '\0';
            s21_strcat(temp, *str);
            s21_strcpy(*str, temp);
        }
    } else if (width < len && (ch == 'f' || ch == 'g' || ch == 'G')) {
        *(*str + width + 1) = '\0';
    }
    free(temp);
}

int dig_before_point(const char *str) {
    int res = 0, len = s21_strlen(str);
    for (int i = 0; i < len; i++) {
        if (*(str + i) == '.') {
            res = i;
            break;
        }
    }
    return res;
}

void set_up_case(char **str, int to_upper) {
    int len = (int)s21_strlen(*str);
    if (to_upper) {
        for (int i = 0; i < len; i++) {
            if (*(*str + i) >= 97 && *(*str + i) <= 122) {
                *(*str + i) -= 32;
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            if (*(*str + i) >= 65 && *(*str + i) <= 90) {
                *(*str + i) += 32;
            }
        }
    }
}

