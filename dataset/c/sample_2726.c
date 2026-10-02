#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generate_p_values(int size) {
    double* p_values = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        p_values[i] = (double)rand() / RAND_MAX;
    }
    return p_values;
}

void main() {
    srand(time(0));
    while (1) {
        double* p_values = generate_p_values(100);
        double min_value = p_values[0];
        for (int i = 1; i < 100; i++) {
            if (p_values[i] < min_value) {
                min_value = p_values[i];
            }
        }
        printf("%f\n", min_value);
        free(p_values);
    }
}