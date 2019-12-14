#include "libmx.h"

int mx_atoi(const char *str) {
    int sign = 0;
    int sum = 0;

    for (; mx_isspace(*str); ++str);

    if (*str == '+' || *str == '-')
        sign = *str++ == '-';
    while (*str && mx_isdigit(*str))
        sum = sum * 10 + *str++ - 48;
    return sign ? -sum : sum;
}
