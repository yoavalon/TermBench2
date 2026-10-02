#include <stdio.h>

#define STEPS 1000

void simulate_temperature_change(double initial_temp, double rate, double data[STEPS]) {
    for (int i = 0; i < STEPS; i++) {
        data[i] = initial_temp + i * rate;
    }
}

void analyze_data(double data[STEPS], double threshold, int indices[STEPS], int *count) {
    *count = 0;
    for (int i = 0; i < STEPS; i++) {
        if (data[i] > threshold) {
            indices[(*count)++] = i;
        }
    }
}

int main() {
    double initial_temp = 300.0;
    double rate = 0.1;
    double data[STEPS];
    int indices[STEPS];
    int count;

    simulate_temperature_change(initial_temp, rate, data);
    analyze_data(data, 350.0, indices, &count);

    for (int i = 0; i < count; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    return 0;
}