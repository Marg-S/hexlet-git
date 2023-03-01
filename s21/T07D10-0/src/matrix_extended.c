#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int input_menu(int *n);
int input_n(int *n1, int *n2);
int input_data(int **a, int n1, int n2);
int stat_input_data(int a[NMAX][NMAX], int n1, int n2);
void output(int **a, int n1, int n2);
void stat_output(int a[NMAX][NMAX], int n1, int n2);
void menu1(int n1, int n2);
void menu2(int n1, int n2);
void menu3(int n1, int n2);
void menu4(int n1, int n2);
void max(int **a, int n1, int n2);
void stat_max(int a[NMAX][NMAX], int n1, int n2);
void min(int **a, int n1, int n2);
void stat_min(int a[NMAX][NMAX], int n1, int n2);

int main() {
    int ret = 0, menu, n1, n2;

    if (input_menu(&menu))
        ret = 1;
    else if (input_n(&n1, &n2))
        ret = 1;

    if (!ret) switch (menu) {
            case 1:
                menu1(n1, n2);
                break;
            case 2:
                menu2(n1, n2);
                break;
            case 3:
                menu3(n1, n2);
                break;
            case 4:
                menu4(n1, n2);
        }

    if (ret) printf("n/a");
    return ret;
}

void menu1(int n1, int n2) {
    int data[NMAX][NMAX];
    if (stat_input_data(data, n1, n2))
        printf("n/a");
    else {
        stat_output(data, n1, n2);
        stat_max(data, n1, n2);
        stat_min(data, n1, n2);
    }
}

void menu2(int n1, int n2) {
    int **data = malloc(n1 * sizeof(int *));
    for (int i = 0; i < n1; i++) data[i] = malloc(n2 * sizeof(int));

    if (input_data(data, n1, n2))
        printf("n/a");
    else {
        output(data, n1, n2);
        max(data, n1, n2);
        min(data, n1, n2);
    }

    for (int i = 0; i < n1; i++) free(data[i]);
    free(data);
}

void menu3(int n1, int n2) {
    int **p_data = malloc(n1 * sizeof(int *));
    int *data = malloc(n1 * n2 * sizeof(int));
    for (int i = 0; i < n1; i++) p_data[i] = data + n2 * i;

    if (input_data(p_data, n1, n2))
        printf("n/a");
    else {
        output(p_data, n1, n2);
        max(p_data, n1, n2);
        min(p_data, n1, n2);
    }

    free(data);
    free(p_data);
}

void menu4(int n1, int n2) {
    int **data = malloc(n1 * n2 * sizeof(int) + n1 * sizeof(int *));
    int *p_data = (int *)(data + n1);
    for (int i = 0; i < n1; i++) data[i] = p_data + n2 * i;

    if (input_data(data, n1, n2))
        printf("n/a");
    else {
        output(data, n1, n2);
        max(data, n1, n2);
        min(data, n1, n2);
    }

    free(data);
}

int input_data(int **a, int n1, int n2) {
    int ret = 0;
    for (int i = 0; i < n1 && !ret; i++) {
        char c;
        for (int j = 0; j < n2; j++) scanf("%d", &a[i][j]);
        c = getchar();
        if (c != '\n') ret = 1;
    }
    return ret;
}

int input_menu(int *n) {
    int ret = 0;
    char c;
    if (scanf("%d%c", n, &c) != 2) ret = 1;
    if (c != '\n' || *n < 1 || *n > 4) ret = 1;
    return ret;
}

int input_n(int *n1, int *n2) {
    int ret = 0;
    scanf("%d", n1);
    if (*n1 <= 0 || *n1 > NMAX)
        ret = 1;
    else {
        char c;
        scanf("%d%c", n2, &c);
        if (c != '\n' || *n2 <= 0 || *n2 > NMAX) ret = 1;
    }
    return ret;
}

int stat_input_data(int a[NMAX][NMAX], int n1, int n2) {
    int ret = 0;

    for (int i = 0; i < n1 && !ret; i++) {
        char c;
        for (int j = 0; j < n2; j++) scanf("%d", &a[i][j]);
        c = getchar();
        if (c != '\n') ret = 1;
    }

    return ret;
}

void output(int **a, int n1, int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][n2 - 1]);
    }
}

void stat_output(int a[NMAX][NMAX], int n1, int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][n2 - 1]);
    }
}

void max(int **a, int n1, int n2) {
    int *max_item = malloc(n1 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        max_item[i] = a[i][0];
        for (int j = 1; j < n2; j++) {
            if (a[i][j] > max_item[i]) max_item[i] = a[i][j];
        }
    }

    for (int i = 0; i < n1 - 1; i++) printf("%d ", max_item[i]);
    printf("%d\n", max_item[n1 - 1]);

    free(max_item);
}

void stat_max(int a[NMAX][NMAX], int n1, int n2) {
    int *max_item = malloc(n1 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        max_item[i] = a[i][0];
        for (int j = 1; j < n2; j++) {
            if (a[i][j] > max_item[i]) max_item[i] = a[i][j];
        }
    }

    for (int i = 0; i < n1 - 1; i++) printf("%d ", max_item[i]);
    printf("%d\n", max_item[n1 - 1]);

    free(max_item);
}

void min(int **a, int n1, int n2) {
    int *min_item = malloc(n2 * sizeof(int));

    for (int j = 0; j < n2; j++) {
        min_item[j] = a[0][j];
        for (int i = 1; i < n1; i++) {
            if (a[i][j] < min_item[j]) min_item[j] = a[i][j];
        }
    }

    for (int i = 0; i < n2 - 1; i++) printf("%d ", min_item[i]);
    printf("%d", min_item[n1 - 1]);

    free(min_item);
}

void stat_min(int a[NMAX][NMAX], int n1, int n2) {
    int *min_item = malloc(n2 * sizeof(int));

    for (int j = 0; j < n2; j++) {
        min_item[j] = a[0][j];
        for (int i = 1; i < n1; i++) {
            if (a[i][j] < min_item[j]) min_item[j] = a[i][j];
        }
    }

    for (int i = 0; i < n2 - 1; i++) printf("%d ", min_item[i]);
    printf("%d", min_item[n1 - 1]);

    free(min_item);
}
