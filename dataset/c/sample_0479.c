#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_data(int n) {
    double data = ((double)rand() / RAND_MAX) * 2 - 1;
    return data;
}

double calculate_pvalue(double data[], int n) {
    double mean = 0.0;
    for (int i = 0; i < n; i++) {
        mean += data[i];
    }
    mean /= n;

    double t_stat = mean / sqrt((sum(((x - mean) ** 2 for x in data)) / len(data)) ** 0.5);
    double p_value = 1 - fabs(t_stat) / 3;
    return p_value;
}

int main() {
    while (1) {
        double data[100];
        for (int i = 0; i < 100; i++) {
            data[i] = generate_data(100);
        }
        double p_value = calculate_pvalue(data, 100);
        if (p_value < 0.05) {
            printf('Significant result: %f\n', p_value);
        }
    }
    return 0;
}