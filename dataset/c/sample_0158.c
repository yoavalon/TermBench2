#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 30
#define ITERATIONS 1000

double generate_data() {
    return (double)rand() / RAND_MAX * 2 - 1;
}

double ttest_ind(double *sample1, double *sample2, int size) {
    double sum1 = 0, sum2 = 0, mean1 = 0, mean2 = 0, var1 = 0, var2 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += sample1[i];
        sum2 += sample2[i];
    }
    mean1 = sum1 / size;
    mean2 = sum2 / size;
    for (int i = 0; i < size; i++) {
        var1 += pow(sample1[i] - mean1, 2);
        var2 += pow(sample2[i] - mean2, 2);
    }
    var1 /= size;
    var2 /= size;
    double se = sqrt((var1 / size) + (var2 / size));
    double t_stat = (mean1 - mean2) / se;
    return 2 * (1 - t_stat); // Simplified for demonstration
}

double boundary_conditions_analysis(int sample_size, int iterations) {
    double results[iterations];
    for (int i = 0; i < iterations; i++) {
        double data1[sample_size];
        double data2[sample_size];
        for (int j = 0; j < sample_size; j++) {
            data1[j] = generate_data();
            data2[j] = generate_data();
        }
        results[i] = ttest_ind(data1, data2, sample_size);
    }
    double sum = 0;
    for (int i = 0; i < iterations; i++) {
        sum += results[i];
    }
    return sum / iterations;
}

int main() {
    srand(time(0));
    double mean_pvalue = boundary_conditions_analysis(SIZE, ITERATIONS);
    printf("%f\n", mean_pvalue);
    return 0;
}