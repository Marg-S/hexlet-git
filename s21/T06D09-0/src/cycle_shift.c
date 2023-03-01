#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
void shift(int *a, int n, int c);
void output(int *a, int n);

int main() {
    int n, c, data[NMAX];
    if (input(data, &n, &c)) {
        printf("n/a");
        return 1;
    }

    shift(data, n, c);
    output(data, n);

    return 0;
}

int input(int *a, int *n, int *shift) {
    scanf("%d", n);
    if (*n <= 0 || *n > NMAX) return 1;
    char c;
    for (int *p = a; p - a < *n; p++) scanf("%d", p);
    scanf("%d", shift);
    c = getchar();
    if (c != '\n') return 1;

    return 0;
}

void shift(int *a, int n, int c) {
    int temp[NMAX];
    for (int i = 0; i < n; i++) temp[i] = a[(i + 10 + c) % 10];
    for (int i = 0; i < n; i++) a[i] = temp[i];
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}