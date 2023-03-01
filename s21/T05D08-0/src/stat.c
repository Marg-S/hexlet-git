#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 1;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

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
    printf("\n");
}

int max(int *a, int n) {
    int max_value = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max_value) max_value = *p;
    }
    return max_value;
}

int min(int *a, int n) {
    int min_value = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min_value) min_value = *p;
    }
    return min_value;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}