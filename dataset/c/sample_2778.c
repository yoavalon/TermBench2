#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute_p_values(int num_trials, int sample_size) {
    double *data = (double *)malloc(sample_size * sizeof(double));
    double *p_values = (double *)malloc((num_trials + 1) * sizeof(double));
    int i;

    for (i = 0; i < sample_size; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    for (i = 0; i < num_trials; i++) {
        p_values[i] = (double)rand() / RAND_MAX;
    }

    while (1) {
        for (i = sample_size - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            double temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        p_values[num_trials] = (double)rand() / RAND_MAX;
        num_trials++;
        p_values = (double *)realloc(p_values, (num_trials + 1) * sizeof(double));
    }

    free(data);
    free(p_values);
}

int main() {
    srand(time(NULL));
    permute_p_values(1000, 50);
    return 0;
}