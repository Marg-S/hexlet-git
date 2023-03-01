#include "data_sort.h"

void sort(double *data, int n) {
    double temp;
    for (double *left = data; left - data < n; left++) {
        double min = *left;
        double *min_p = left;
        for (double *right = left + 1; right - data < n; right++) {
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
