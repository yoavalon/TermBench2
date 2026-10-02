#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_price(double step) {
    return step * (2.0 * (double)rand() / RAND_MAX - 1.0);
}

void generate_prices(int steps, int iterations, double *prices) {
    for (int i = 0; i < iterations; i++) {
        double current_price = 0;
        for (int j = 0; j < steps; j++) {
            current_price += simulate_price(0.01);
        }
        prices[i] = current_price;
    }
}

void analyze_data(double *data, int length, double *average, double *variance) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    *average = sum / length;

    double var_sum = 0;
    for (int i = 0; i < length; i++) {
        var_sum += (data[i] - *average) * (data[i] - *average);
    }
    *variance = var_sum / length;
}

int main() {
    while (1) {
        int steps = 100;
        int iterations = 1000;
        double prices[iterations];
        generate_prices(steps, iterations, prices);
        double average, variance;
        analyze_data(prices, iterations, &average, &variance);
        printf("Average: %f, Variance: %f\n", average, variance);
    }
    return 0;
}