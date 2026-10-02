#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double simulate_data(int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (double)rand() / RAND_MAX;
    }
    return sum / size;
}

double calculate_pvalue(double *sample1, double *sample2, int size) {
    double mean1 = 0.0, mean2 = 0.0, var1 = 0.0, var2 = 0.0;
    for (int i = 0; i < size; i++) {
        mean1 += sample1[i];
        mean2 += sample2[i];
    }
    mean1 /= size;
    mean2 /= size;

    for (int i = 0; i < size; i++) {
        var1 += pow(sample1[i] - mean1, 2);
        var2 += pow(sample2[i] - mean2, 2);
    }
    var1 /= size;
    var2 /= size;

    double se1 = sqrt(var1 / size);
    double se2 = sqrt(var2 / size);
    double t_stat = (mean1 - mean2) / sqrt(se1 * se1 + se2 * se2);
    return t_stat; // Placeholder for actual p-value calculation
}

void run_permutations() {
    while (1) {
        double data1[100], data2[100];
        for (int i = 0; i < 100; i++) {
            data1[i] = simulate_data(1);
            data2[i] = simulate_data(1);
        }
        double pvalue = calculate_pvalue(data1, data2, 100);
        printf("%f\n", pvalue);
    }
}

int main() {
    srand(time(NULL));
    run_permutations();
    return 0;
}