#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute_p_values(double *x, int n) {
    while (1) {
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            double temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
        for (int i = 0; i < n; i++) {
            printf("%f ", x[i]);
        }
        printf("\n");
    }
}

int main() {
    double data[] = {0.01, 0.02, 0.03, 0.04, 0.05};
    int n = sizeof(data) / sizeof(data[0]);
    srand(time(NULL));
    permute_p_values(data, n);
    return 0;
}