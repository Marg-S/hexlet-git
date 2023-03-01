#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    int ret = 0, n = 0;
    char c;

    scanf("%d%c", &n, &c);
    if (c == '\n' && n > 0) {
        double *data;
        data = malloc(n * sizeof(double));
        input(data, n);

        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");

        free(data);
    } else {
        ret = 1;
        printf("n/a");
    }

    return ret;
}
