#include <stdio.h>
#define LEN 100

int input(int *a, int *count_a, int *b, int *count_b);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void output(int *a, int n, int *b, int nn);

int main() {
    int a1[LEN], a2[LEN], a_sum[LEN], a_sub[LEN], count_a1, count_a2, count_sum, count_sub;

    if (input(a1, &count_a1, a2, &count_a2)) {
        printf("n/a");
        return 1;
    }
    sum(a1, count_a1, a2, count_a2, a_sum, &count_sum);
    sub(a1, count_a1, a2, count_a2, a_sub, &count_sub);
    output(a_sum, count_sum, a_sub, count_sub);
}

int input(int *a, int *count_a, int *b, int *count_b) {
    int item;
    char c;

    int *p = a;
    do {
        if (scanf("%d%c", &item, &c) != 2) return 1;
        if (item >= 0 && item < 10 && p - a < LEN)
            *p = item;
        else
            return 1;
        if (c != ' ' && c != '\n') return 1;
        p++;
    } while (c == ' ');
    *count_a = p - a;

    p = b;
    do {
        if (scanf("%d%c", &item, &c) != 2) return 1;
        if (item >= 0 && item < 10 && p - b < LEN)
            *p = item;
        else
            return 1;
        if (c != ' ' && c != '\n') return 1;
        p++;
    } while (c == ' ');
    *count_b = p - b;

    return 0;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int result_temp[LEN], *res_temp = result_temp, *p_max, *p_min, *start_max, *start_min, eq = 0, carry = 0;

    p_max = buff1 + len1 - 1;
    start_max = buff1;
    p_min = buff2 + len2 - 1;
    start_min = buff2;
    *result_length = len2;

    if (len1 == len2)
        eq = 1;
    else if (len1 < len2) {
        p_max = buff2 + len2 - 1;
        start_max = buff2;
        p_min = buff1 + len1 - 1;
        start_min = buff1;
        *result_length = len1;
    }

    for (int temp; p_min >= start_min; p_max--, p_min--) {
        temp = *p_max + *p_min + carry;
        *res_temp = temp % 10;
        carry = temp / 10;
        res_temp++;
    }

    if (eq) {
        if (carry) {
            *result = carry;
            (*result_length)++;
        }
    } else {
        for (int temp; p_max >= start_max; p_max--) {
            temp = *p_max + carry;
            *res_temp = temp % 10;
            carry = temp / 10;
            res_temp++;
            (*result_length)++;
        }
    }

    int j;
    for (j = *result_length - 1; result_temp[j] == 0; j--) (*result_length)--;
    for (int *i = result; j >= 0; i++, j--) *i = result_temp[j];
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int result_temp[LEN], *res_temp = result_temp, *p_max, *p_min, *start_max, *start_min, carry;

    if (len1 < len2)
        *result_length = -1;
    else if (len1 == len2) {
        int *p1 = buff1, *p2 = buff2;
        while (*p1 == *p2) p1++, p2++;
        if (*p1 < *p2) *result_length = -1;
    }

    if (*result_length != -1) {
        p_max = buff1 + len1 - 1;
        start_max = buff1;
        p_min = buff2 + len2 - 1;
        start_min = buff2;
        *result_length = len2;

        for (carry = 0; p_min >= start_min; p_max--, p_min--) {
            *res_temp = *p_max - carry;
            if (*p_max < *p_min) {
                carry = 1;
                *res_temp += 10;
            } else
                carry = 0;
            *res_temp -= *p_min;
            res_temp++;
        }

        while (p_max >= start_max) {
            *res_temp = *p_max - carry;
            if (*p_max < 0) {
                carry = 1;
                *res_temp += 10;
            }
            res_temp++;
            (*result_length)++;
            p_max--;
        }

        int j;
        for (j = *result_length - 1; result_temp[j] == 0; j--) (*result_length)--;
        for (int *i = result; j >= 0; i++, j--) *i = result_temp[j];
    }
}

void output(int *a, int n_a, int *b, int n_b) {
    for (int *p = a; p - a < n_a; p++) {
        printf("%d ", *p);
    }
    printf("\n");
    if (n_b == -1)
        printf("n/a");
    else
        for (int *p = b; p - b < n_b; p++) printf("%d ", *p);
}