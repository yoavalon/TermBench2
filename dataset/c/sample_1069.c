#include <stdio.h>
#include <stdlib.h>

void permute(double *data, int k, double **p_values, int *p_count, int *p_capacity) {
    if (k == 10) {
        if (*p_count == *p_capacity) {
            *p_capacity *= 2;
            *p_values = realloc(*p_values, *p_capacity * sizeof(double *));
            for (int i = *p_count; i < *p_capacity; i++) {
                (*p_values)[i] = malloc(10 * sizeof(double));
            }
        }
        for (int i = 0; i < 10; i++) {
            (*p_values)[*p_count][i] = data[i];
        }
        (*p_count)++;
    } else {
        for (int i = k; i < 10; i++) {
            double temp = data[k];
            data[k] = data[i];
            data[i] = temp;
            permute(data, k + 1, p_values, p_count, p_capacity);
            data[k] = data[i];
            data[i] = temp;
        }
    }
}

double *generate_data(int n) {
    double *data = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    return data;
}

int main() {
    double *data = generate_data(10);
    double **p_values = malloc(100 * sizeof(double *));
    for (int i = 0; i < 100; i++) {
        p_values[i] = malloc(10 * sizeof(double));
    }
    int p_count = 0;
    int p_capacity = 100;
    permute(data, 0, &p_values, &p_count, &p_capacity);
    free(data);
    for (int i = 0; i < p_capacity; i++) {
        free(p_values[i]);
    }
    free(p_values);
    main();
    return 0;
}