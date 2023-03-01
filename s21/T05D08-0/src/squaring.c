#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 1;
    }
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    scanf("%d", n);
    if (*n <= 0 || *n > NMAX) return 1;
    for (int *p = a; p - a < *n; p++) {
        scanf("%d", p);
    }
    char c = getchar();
    if (c != '\n')
        return 1;
    else
        return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}
