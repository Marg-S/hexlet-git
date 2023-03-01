#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int n = NMAX, data[NMAX];
    if (input(data)) {
        printf("n/a");
        return 1;
    }
    sort(data, n);
    output(data, n);
    return 0;
}

int input(int *a) {
    char c;
    for (int *p = a; p - a < NMAX; p++) scanf("%d", p);
    c = getchar();
    if (c != '\n')
        return 1;
    else
        return 0;
}

void sort(int *a, int n) {
    int *min_p, min, temp;
    for (int *left = a; left - a < n; left++) {
        min = *left;
        min_p = left;
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
