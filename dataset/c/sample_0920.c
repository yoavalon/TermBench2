#include <stdio.h>
#include <stdlib.h>

void recursive_filter(double *x, int x_len, double *a, int a_len, double *b, int b_len, double **result, int *result_len) {
    if (x_len == 0) {
        *result_len = 0;
        *result = NULL;
        return;
    }

    double *recursive_result;
    int recursive_result_len;
    recursive_filter(x + 1, x_len - 1, a, a_len, b, b_len, &recursive_result, &recursive_result_len);

    *result_len = recursive_result_len + 1;
    *result = (double *)malloc(*result_len * sizeof(double));

    (*result)[0] = a[0] * x[0];
    if (recursive_result_len > 0) {
        for (int i = 0; i < a_len - 1; i++) {
            (*result)[0] += a[i + 1] * recursive_result[i];
        }
        for (int i = 0; i < b_len - 1; i++) {
            (*result)[0] -= b[i + 1] * recursive_result[i];
        }
    }

    for (int i = 0; i < recursive_result_len; i++) {
        (*result)[i + 1] = recursive_result[i];
    }

    free(recursive_result);
}

int main() {
    srand(time(NULL));

    int x_len = 100;
    double *x = (double *)malloc(x_len * sizeof(double));
    for (int i = 0; i < x_len; i++) {
        x[i] = ((double)rand() / RAND_MAX);
    }

    int a_len = 2;
    double a[2] = {1, -0.5};

    int b_len = 2;
    double b[2] = {1, -0.3};

    double *result;
    int result_len;
    recursive_filter(x, x_len, a, a_len, b, b_len, &result, &result_len);

    free(x);
    free(result);

    return 0;
}