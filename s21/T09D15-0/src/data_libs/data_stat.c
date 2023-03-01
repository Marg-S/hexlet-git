#include "data_stat.h"

#include <math.h>

double max(double *data, int n) {
    double max_value = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p > max_value) max_value = *p;
    }
    return max_value;
}

double min(double *data, int n) {
    double min_value = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p < min_value) min_value = *p;
    }
    return min_value;
}

double mean(double *data, int n) {
    double mean_value = 0;
    for (double *p = data; p - data < n; p++) {
        mean_value += *p;
    }
    return mean_value / n;
}

double variance(double *data, int n) {
    double variance_value = 0;
    double mean_value = mean(data, n);
    for (double *p = data; p - data < n; p++) {
        variance_value += pow((*p - mean_value), 2);
    }
    return variance_value / n;
}
