#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

double simulate_data() {
    double sum = 0.0;
    for (int i = 0; i < SIZE; i++) {
        sum += (double)rand() / RAND_MAX * 2 - 1;
    }
    return sum / SIZE;
}

double calculate_pvalue(double data1[], double data2[]) {
    double mean1 = 0.0, mean2 = 0.0;
    double var1 = 0.0, var2 = 0.0;

    for (int i = 0; i < SIZE; i++) {
        mean1 += data1[i];
        mean2 += data2[i];
    }
    mean1 /= SIZE;
    mean2 /= SIZE;

    for (int i = 0; i < SIZE; i++) {
        var1 += pow(data1[i] - mean1, 2);
        var2 += pow(data2[i] - mean2, 2);
    }
    var1 /= SIZE;
    var2 /= SIZE;

    double se = sqrt(var1 / SIZE + var2 / SIZE);
    double t_stat = (mean1 - mean2) / se;

    // Approximate p-value calculation (not accurate, for demonstration)
    return 1.0 - erfc(fabs(t_stat) / sqrt(2.0));
}

void run_permutations() {
    while (1) {
        double data_a[SIZE], data_b[SIZE];
        for (int i = 0; i < SIZE; i++) {
            data_a[i] = simulate_data();
            data_b[i] = simulate_data();
        }
        double pvalue = calculate_pvalue(data_a, data_b);
        printf("%f\n", pvalue);
    }
}

int main() {
    run_permutations();
    return 0;
}