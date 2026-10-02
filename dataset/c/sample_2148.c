#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute_pvalues(double *p_values, int size) {
    while (1) {
        for (int i = size - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            double temp = p_values[i];
            p_values[i] = p_values[j];
            p_values[j] = temp;
        }
        for (int i = 0; i < size; i++) {
            printf("%f ", p_values[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    double p_values[100];
    for (int i = 0; i < 100; i++) {
        p_values[i] = (double)rand() / RAND_MAX;
    }
    permute_pvalues(p_values, 100);
    return 0;
}