#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int sum);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int *numbers);

int main() {
    int n, count, data[NMAX], numbers[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 1;
    }
    int sum = sum_numbers(data, n);
    if (sum == -1) {
        printf("n/a");
        return 1;
    }
    count = find_numbers(data, n, numbers);
    output(numbers, count, sum);
    return 0;
}

int input(int *buffer, int *length) {
    scanf("%d", length);
    if (*length <= 0 || *length > NMAX) return 1;
    char c;
    for (int *p = buffer; p - buffer < *length; p++) scanf("%d", p);
    c = getchar();
    if (c != '\n') return 1;

    return 0;
}

int sum_numbers(int *buffer, int length) {
    int sum = 0, even = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
            even++;
        }
    }
    if (!even) return -1;
    return sum;
}

int find_numbers(int *buffer, int length, int *numbers) {
    int n = 0, sum = sum_numbers(buffer, length);
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p && sum % *p == 0) {
            *numbers = *p;
            numbers++;
            n++;
        }
    }
    return n;
}

void output(int *buffer, int length, int sum) {
    printf("%d\n", sum);
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d ", *p);
    }
}