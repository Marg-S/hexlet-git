#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int searching(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 1;
    }
    printf("%d", searching(data, n));
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

double mean(int *a, int n) {
    double mean_value = 0;
    for (int *p = a; p - a < n; p++) {
        mean_value += *p;
    }
    return mean_value / n;
}

double variance(int *a, int n) {
    double variance_value = 0;
    double mean_value = mean(a, n);
    for (int *p = a; p - a < n; p++) {
        variance_value += pow((*p - mean_value), 2);
    }
    return variance_value / n;
}

int searching(int *a, int n) {
    double mean_value = mean(a, n);
    double variance_value = variance(a, n);
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= mean_value && *p <= mean_value + 3 * sqrt(variance_value) && *p) return *p;
    }
    return 0;
}
