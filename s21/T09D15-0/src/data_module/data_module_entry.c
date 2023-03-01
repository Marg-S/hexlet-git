#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    int ret = 0, n = 0;
    char c;

    scanf("%d%c", &n, &c);
    if (c == '\n' && n > 0) {
        double *data;
        data = malloc(n * sizeof(double));

        input(data, n);

        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");

        free(data);
    } else {
        ret = 1;
        printf("n/a");
    }

    return ret;
}
