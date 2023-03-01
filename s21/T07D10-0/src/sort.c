#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int input_n(int *n);
int input_data(int *a, int n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int ret = 0, n, *data = NULL;
    if (input_n(&n)) {
        printf("n/a");
        ret = 1;
    } else {
        data = (int *)malloc(n * sizeof(int));

        if (input_data(data, n)) {
            printf("n/a");
            ret = 1;
        } else {
            sort(data, n);
            output(data, n);
            free(data);
        }
    }
    return ret;
}

int input_n(int *n) {
    int ret = 0;
    char c;
    if (scanf("%d%c", n, &c) != 2)
        ret = 1;
    else if (c != '\n' || *n <= 0 || *n > NMAX)
        ret = 1;
    return ret;
}

int input_data(int *a, int n) {
    char c;
    int ret = 0;

    for (int *p = a; p - a < n; p++) scanf("%d", p);
    c = getchar();
    if (c != '\n') ret = 1;

    return ret;
}

void sort(int *a, int n) {
    int temp;
    for (int *left = a; left - a < n; left++) {
        int min = *left;
        int *min_p = left;
        for (int *right = left + 1; right - a < n; right++) {
            if (*right < min) {
                min = *right;
                min_p = right;
            }
        }
        if (min_p != left) {
            temp = *left;
            *left = min;
            *min_p = temp;
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}
