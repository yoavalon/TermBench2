#include <stdio.h>
#include <math.h>

double decay_function(double value, double rate, int precision) {
    return round(value * (1 - rate) * pow(10, precision)) / pow(10, precision);
}

void simulate_decay(double initial_value, double decay_rate, int precision, int steps, double *values) {
    values[0] = initial_value;
    for (int i = 1; i <= steps; i++) {
        double current_value = values[i - 1];
        double new_value = decay_function(current_value, decay_rate, precision);
        values[i] = new_value;
    }
}

int main() {
    double initial_value = 1.0;
    double decay_rate = 0.1;
    int precision = 4;
    int steps = 10;
    double result[steps + 1];
    simulate_decay(initial_value, decay_rate, precision, steps, result);
    for (int i = 0; i <= steps; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    return 0;
}