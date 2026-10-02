#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(double *array, size_t n) {
    if (n > 1) {
        size_t i;
        srand(time(NULL));
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            double t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void permute_p_values(double *p_values) {
    shuffle(p_values, 5);
    permute_p_values(p_values);
}

void main() {
    double data[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    permute_p_values(data);
}