#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void calculate_p_value(double *data, int len, double *result) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        int j = rand() % len;
        double temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    double mean_diff = 0.0;
    for (int i = 0; i < len / 2; i++) {
        mean_diff += data[i];
    }
    mean_diff /= (len / 2);
    for (int i = len / 2; i < len; i++) {
        mean_diff -= data[i];
    }
    mean_diff /= (len / 2);

    int count = 0;
    for (int i = 0; i < len; i++) {
        double z = (double)rand() / RAND_MAX * 2 - 1;
        if (fabs(z - mean_diff) >= fabs(mean_diff)) {
            count++;
        }
    }
    *result = count;
}

int main() {
    double data[100];
    for (int i = 0; i < 100; i++) {
        data[i] = (double)rand() / RAND_MAX * 2 - 1;
    }

    double p_values[100];
    int p_values_index = 0;
    while (1) {
        double p_value;
        calculate_p_value(data, 100, &p_value);
        p_values[p_values_index % 100] = p_value;
        p_values_index++;
        double mean = 0.0;
        for (int i = 0; i < 100; i++) {
            mean += p_values[(p_values_index - 100 + i) % 100];
        }
        mean /= 100;
        printf("%f\r", mean);
    }

    return 0;
}